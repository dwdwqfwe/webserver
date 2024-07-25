#include "config.h"
#include <bits/getopt_core.h>
#include <cstdlib>
#include <unistd.h>

Config::Config()
{
    PORT=9906;
    Log_write=0;
    sql_num=8;
    thread_num=8;
    actor_mod=0;
    Connt_mod=0;
    Listen_mod=0;
    close_log=0;
    OPT_LINK=0;
    Tring_mod=0;
}
void Config::parse_arg(int argc,char *argv[])
{
    string str="p:l:m:o:s:t:c:a:";
    char get_char;
    while((get_char=getopt(argc,argv,str.c_str()))!=-1){
        switch(get_char){
            case 'p':
            {
                PORT=atoi(optarg);
                break;
            }
            case 'l':
            {
                Log_write=atoi(optarg);
                break;
            }
            case 'm':
            {
                Tring_mod=atoi(optarg);
                break;
            }
            case 'o':
            {
                OPT_LINK=atoi(optarg);
                break;
            }
            case 's':
            {
                sql_num=atoi(optarg);
                break;
            }
            case 't':
            {
                thread_num=atoi(optarg);
                break;
            }
            case 'c':
            {
                close_log=atoi(optarg);
                break;
            }
            case 'a':
            {
                actor_mod=atoi(optarg);
                break;
            }
            default:
                break;
        }
    }
}