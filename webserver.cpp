#include "webserver.h"
#include "http/http_conn.h"
#include "log/log.h"
#include "thread_pool/threadpool.h"
#include "timer/lst_timer.h"
#include <bits/types/timer_t.h>
#include <cassert>
#include <cerrno>
#include <csignal>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

WebServer::WebServer()
{
    users=new http_conn[MAX_FD];
    char server_path[200];
    getcwd(server_path,200);
    char root[6]="/root";
    m_root=(char*)malloc(strlen(server_path)+strlen(root)+1);
    strcpy(m_root,server_path);
    strcat(m_root,root);
    users_timer=new client_data[MAX_FD];
}

WebServer::~WebServer()
{
    close(m_listenfd);
    close(m_epollfd);
    close(m_pipefd[0]);
    close(m_pipefd[1]);
    delete users;
    delete m_pool;
    delete users_timer;
}

void WebServer::init(int port, string user, string passWord, string databaseName, int log_write, 
                     int opt_linger, int trigmode, int sql_num, int thread_num, int close_log, int actor_model)
{
    m_port=port;
    m_user=user;
    m_passWord=passWord;
    m_databaseName=databaseName;
    m_log_write=log_write;
    m_OPT_LINGER=opt_linger;
    m_TRIGMode=trigmode;
    m_sql_num=sql_num;
    m_thread_num=thread_num;
    m_close_log=close_log;
    m_actormodel=actor_model;
}

void WebServer::trig_mode()
{
    //LT + LT
    if (0 == m_TRIGMode)
    {
        m_LISTENTrigmode = 0;
        m_CONNTrigmode = 0;
    }
    //LT + ET
    else if (1 == m_TRIGMode)
    {
        m_LISTENTrigmode = 0;
        m_CONNTrigmode = 1;
    }
    //ET + LT
    else if (2 == m_TRIGMode)
    {
        m_LISTENTrigmode = 1;
        m_CONNTrigmode = 0;
    }
    //ET + ET
    else if (3 == m_TRIGMode)
    {
        m_LISTENTrigmode = 1;
        m_CONNTrigmode = 1;
    }
}

void WebServer::log_write()
{
    if(m_close_log){
        if(m_log_write)
            Log::get_instance()->init("./ServerLog", m_close_log, 2000, 800000, 800);
        else
            Log::get_instance()->init("./ServerLog", m_close_log, 2000, 800000,0);
    }
}

void WebServer::sql_pool()
{
    m_connPool=connection_pool::GetInstance();
    m_connPool->init("localhost",m_user,m_passWord,m_databaseName,3306,m_sql_num,m_close_log);
    users->initmysql_result(m_connPool);
}

void WebServer::thread_pool()
{
   m_pool=new threadpool<http_conn>(m_actormodel,m_connPool,m_thread_num);
}

void WebServer::eventListen()
{
    m_listenfd=socket(AF_INET,SOCK_STREAM,0);
    assert(m_listenfd>0);
    if (0 == m_OPT_LINGER)
    {
        
        struct linger tmp = {0, 1};
        setsockopt(m_listenfd, SOL_SOCKET, SO_LINGER, &tmp, sizeof(tmp));
    }
    else if (1 == m_OPT_LINGER)
    {
        struct linger tmp = {1, 1};
        setsockopt(m_listenfd, SOL_SOCKET, SO_LINGER, &tmp, sizeof(tmp));
    }
    
    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(m_port);

    int flag = 1;
    setsockopt(m_listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
    ret = bind(m_listenfd, (struct sockaddr *)&address, sizeof(address));
    assert(ret >= 0);
    ret = listen(m_listenfd, 5);
    assert(ret >= 0);

    utils.init(TIMESLOT);
    struct epoll_event events[MAX_EVENT_NUMBER];
    m_epollfd=epoll_create(5);
    assert(m_epollfd!=-1);
    utils.addfd(m_epollfd,m_listenfd,0,m_TRIGMode);
    http_conn::m_epollfd=m_epollfd;

    ret=socketpair(AF_INET,SOCK_STREAM,0,m_pipefd);
    assert(ret!=-1);
    
    utils.setnonblocking(m_pipefd[1]);

    utils.addfd(m_epollfd,m_pipefd[0],0,m_TRIGMode);

    utils.addsig(SIGPIPE, SIG_IGN);
    utils.addsig(SIGALRM, utils.sig_handler, false);
    utils.addsig(SIGTERM, utils.sig_handler, false);

    alarm(TIMESLOT);

    Utils::u_pipefd=m_pipefd;
    Utils::u_epollfd=m_epollfd;

}

void WebServer::timer(int connfd, struct sockaddr_in client_address)
{
    users[connfd].init(connfd,client_address,m_root,m_CONNTrigmode,m_TRIGMode,m_user,m_passWord,m_databaseName);
    users_timer[connfd].address=client_address;
    users_timer[connfd].sockfd=connfd;
    util_timer *tmp=new util_timer;
    tmp->cb_func=cb_func;
    time_t cur=time(NULL);
    tmp->expire=(timer_t)(cur+3 * TIMESLOT);
    tmp->user_data=&users_timer[connfd];
    users_timer->timer=tmp;
    utils.m_timer_lst.add_timer(tmp);
}

//若有数据传输，则将定时器往后延迟3个单位
//并对新的定时器在链表上的位置进行调整
void WebServer::adjust_timer(util_timer *timer)
{
    time_t cur=time(NULL);
    timer->expire=(timer_t)(cur+3*TIMESLOT);
    utils.m_timer_lst.adjust_timer(timer);
    LOG_INFO("%s", "adjust timer once");
}

void WebServer::deal_timer(util_timer *timer, int sockfd)
{
    if(!timer)
        return;
    timer->cb_func(&users_timer[sockfd]);
    utils.m_timer_lst.del_timer(timer);
    
    LOG_INFO("close fd %d", users_timer[sockfd].sockfd);
}

bool WebServer::dealclientdata()
{
    struct sockaddr_in client_address;
    socklen_t client_length=sizeof(client_address);
    if(m_LISTENTrigmode==0){
        int connfd=accept(m_listenfd,(struct sockaddr*)&client_address,&client_length);
        if(connfd<0){
            LOG_ERROR("%s:errno is:%d", "accept error", errno);
            return false;
        }
        if(http_conn::m_user_count>=MAX_FD){
            utils.show_error(connfd,"webserver is too busy\n");
            LOG_ERROR("%s", "Internal server busy");
            return false;
        }
        timer(connfd,client_address);
    }
    else{
        while(1){
            int connfd=accept(m_listenfd, (struct sockaddr *)&client_address,&client_length);
            if(connfd<0){
                if(connfd==EAGAIN){
                    continue;
                }
                LOG_ERROR("%s:errno is:%d", "accept error", errno);
                break;
            }
            if(http_conn::m_user_count>=MAX_FD){
                utils.show_error(connfd, "Internal server busy");
                LOG_ERROR("%s", "Internal server busy");
                return false;
            }
            timer(connfd,client_address);
        }
        return false;

    }
    return true;
}

bool WebServer::dealwithsignal(bool &timeout, bool &stop_server)
{
   char signal[1024];
   int ret;
   ret=recv(m_pipefd[0],signal,sizeof(signal),0);
   if(ret<=0)
        return false;
    for(int i=0;i<ret;i++){
        switch(signal[i])
        {
            case SIGTERM:
            {
                stop_server=1;
                break;
            }
            case SIGALRM:
            {
                timeout=1;
                break;
            }
        }
    }
    return true;
}

void WebServer::dealwithread(int sockfd)
{
    util_timer *timer=users_timer[sockfd].timer;
    if(m_actormodel==1){
        if(timer){
            adjust_timer(timer);
        }
        m_pool->append(users+sockfd,0);
        while(true){
            if(users[sockfd].improv){
                if(users[sockfd].timer_flag){
                    deal_timer(timer,sockfd);
                    users[sockfd].timer_flag=0;
                }
                users[sockfd].improv=0;
                break;
            }
        }
    }
    else{
        if (users[sockfd].read_once())
        {
            LOG_INFO("deal with the client(%s)", inet_ntoa(users[sockfd].get_address()->sin_addr));

            //若监测到读事件，将该事件放入请求队列
            m_pool->append_p(users + sockfd);

            if (timer)
            {
                adjust_timer(timer);
            }
        }
        else
        {
            deal_timer(timer, sockfd);
        }
    }
}

void WebServer::dealwithwrite(int sockfd)
{
    util_timer *timer = users_timer[sockfd].timer;
    //reactor
    if (1 == m_actormodel)
    {
        if (timer)
        {
            adjust_timer(timer);
        }

        m_pool->append(users + sockfd, 1);

        while (true)
        {
            if (1 == users[sockfd].improv)
            {
                if (1 == users[sockfd].timer_flag)
                {
                    deal_timer(timer, sockfd);
                    users[sockfd].timer_flag = 0;
                }
                users[sockfd].improv = 0;
                break;
            }
        }
    }
    else
    {
        //proactor
        if (users[sockfd].write())
        {
            LOG_INFO("send data to the client(%s)", inet_ntoa(users[sockfd].get_address()->sin_addr));

            if (timer)
            {
                adjust_timer(timer);
            }
        }
        else
        {
            deal_timer(timer, sockfd);
        }
    }
}

void WebServer::eventLoop()
{
   bool timeout=false;
   bool stop_over=false;
   while(1){
    int number=epoll_wait(m_epollfd,events,MAX_EVENT_NUMBER,timeout);
    if(number<0&&errno!=EINTR){
         LOG_ERROR("%s", "epoll failure");
            break;
    }
    for(int i=0;i<number;i++){
        int sockfd=events[i].data.fd;
        if(sockfd==m_listenfd){
            bool flag=dealclientdata();
            if(flag==false)
                continue;
        }
        else if(events[i].events&(EPOLLHUP|EPOLLRDBAND||EPOLLERR)){
            util_timer *timer=users_timer[sockfd].timer;
            deal_timer(timer,sockfd);
        }
        else if(sockfd==m_pipefd[0]&&(events[i].events&EPOLLIN)){
            bool flag=dealwithsignal(timeout,stop_over);
            if(flag==false){
                LOG_ERROR("%s", "dealsinal failure");
            }
        }
        else if (events[i].events & EPOLLIN){
                dealwithread(sockfd);
            }
        else if (events[i].events & EPOLLOUT){
                dealwithwrite(sockfd);
            }
    }
    if(timeout){
        utils.timer_handler();
        LOG_INFO("%s","timer tick");
        timeout=false;
    }
   }
}
