#include "lst_timer.h"
#include "../http/http_conn.h"

sort_timer_lst::sort_timer_lst()
{
   head=NULL;
   tail=NULL;
}
sort_timer_lst::~sort_timer_lst()
{
    util_timer *tmp=head;
    while(head){
        head=tmp->next;
        delete tmp;
        tmp=head;
    }
    head=NULL;
    tail=NULL;
}

void sort_timer_lst::add_timer(util_timer *timer)
{
  if(!timer){
    return;
  }
  if(!head){
    head=timer;
    tail=timer;
    return ;
  }
  if(timer->expire<head->expire){
    timer->next=head;
    head->pre=timer;
    head=timer;
    return;
  }
  add_timer(timer,head);
}
void sort_timer_lst::adjust_timer(util_timer *timer)
{
    if(!timer){
        return;
    }
    util_timer *tmp=timer->next;
    if(!tmp||tmp->expire>timer->expire){
        return;
    }
    if(head==tmp){
        head=head->next;
        head->pre=NULL;
        timer->next=NULL;
        add_timer(timer,head);
    }
    else{
        timer->pre->next=timer->next;
        timer->next->pre=timer->pre;
        timer->next=NULL;
        timer->pre=NULL;
        add_timer(timer,head);
    }
}
void sort_timer_lst::del_timer(util_timer *timer)
{
   if(!timer){
    return;
   }
   if(head==timer&&tail==timer){
    delete timer;
    head=NULL;
    tail=NULL;
    return;
   }
   if(head==timer){
    head=head->next;
    head->pre=NULL;
    delete timer;
    return;
   }
   if(timer==tail){
    tail=tail->pre;
    tail->next=NULL;
    delete timer;
    return;
   }
   timer->pre->next=timer->next;
   timer->next->pre=timer->pre;
   delete timer;

}
void sort_timer_lst::tick()
{
    if(!head){
        return;
    }
    time_t cur=time(NULL);
    util_timer *tmp=head;
    while(tmp){
        if(cur < (time_t)tmp->expire){
            break;
        }
        tmp->cb_func(tmp->user_data);
        head=head->next;
        if(head){
            head->pre=NULL;
        }
        delete tmp;
        tmp=head;
    }
}

void sort_timer_lst::add_timer(util_timer *timer, util_timer *lst_head)
{
    util_timer *pre=lst_head;
    util_timer *tmp=pre->next;
    while(tmp){
        if(tmp->expire>timer->expire){
            tmp->pre->next=timer;
            timer->pre=tmp->pre;
            tmp->pre=timer;
            timer->next=tmp;
        }
        pre=tmp;
        tmp=tmp->next;
    }
    if(!tmp){
        pre->next=tmp;
        timer->pre=pre;
        timer->next=NULL;
        tail=timer;
    }
}

void Utils::init(int timeslot)
{
    m_TIMERSLOT=timeslot;
}

int Utils::setnonblocking(int fd)
{
    int old_option=fcntl(fd,F_GETFL);
    old_option|=O_NONBLOCK;
    fcntl(fd,F_SETFL);
    return old_option;
}

void Utils::addfd(int epollfd, int fd, bool one_shot, int TRIGMode)
{
    epoll_event event;
    memset(&event,0,sizeof(event));
    event.data.fd=fd;
    if(TRIGMode==1){
        event.events=EPOLLIN|EPOLLET|EPOLLRDHUP;
    }
    else{
        event.events=EPOLLIN|EPOLLRDHUP;
    }
    if(one_shot){
        event.events|=EPOLLONESHOT;
    }
    setnonblocking(fd);
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
}
void Utils::sig_handler(int sig)
{
   int save=errno;
   int msg=sig;
   send(u_pipefd[1],(void*)&msg,1,0);
   errno=save;
}
void Utils::addsig(int sig, void(handler)(int), bool restart)
{
    struct sigaction sigact;
    memset(&sigact,0,sizeof(sigact));
    sigact.sa_handler=handler;
    if(restart){
        sigact.sa_flags|=SA_RESTART;
    }
    sigfillset(&sigact.sa_mask);
    assert(sigaction(sig,&sigact,NULL)!=-1);
}

void Utils::timer_handler()
{
    m_timer_lst.tick();
    alarm(m_TIMERSLOT);
}

void Utils::show_error(int connfd, const char *info)
{
    send(connfd,info,strlen(info),0);
    close(connfd);
}

int *Utils::u_pipefd = 0;
int Utils::u_epollfd = 0;

class Utils;
void cb_func(client_data *user_data)
{
   epoll_ctl(Utils::u_epollfd,EPOLL_CTL_DEL,user_data->sockfd,0);
   assert(user_data);
   close(user_data->sockfd);
   http_conn::m_user_count--;
}