#ifndef CONFIG_H
#define CONFIG_H

#include "webserver.h"

using namespace std;

class Config
{
public:
    Config();
    ~Config(){};
    int PORT;
    int Log_write;
    int Tring_mod;
    int Listen_mod;
    int Connt_mod;
    int OPT_LINK;
    int sql_num;
    int thread_num;
    int close_log;
    int actor_mod;
    void parse_arg(int argc,char* argv[]);
};

#endif