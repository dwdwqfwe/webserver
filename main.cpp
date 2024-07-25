#include "config.h"
struct user{
    string username;
    string password;
    string database;
};
int main(int argc,char *argv[])
{
    if(argc<9){
        cout<<"arg too less"<<endl;
        return 0;
    }
    user user;
    user.username="root";
    user.password="123456";
    user.database="jhdb";
    Config config;
    config.parse_arg(argc,argv);
    WebServer server;

    server.init(config.PORT, user.username, user.password, user.database, config.Log_write, 
                config.OPT_LINK, config.Tring_mod,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_mod);
    

    server.log_write();

    server.sql_pool();

    server.thread_pool();

    server.trig_mode();

    server.eventListen();

    server.eventLoop();

    return 0;
}