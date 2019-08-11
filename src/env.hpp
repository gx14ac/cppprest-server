// Copyright © 2019 netSk8ight. All Rights Reserved. 

#ifndef __ENV_H__
#define __ENV_H__

#include <string>
#include <iostream>

using namespace std;

class Env
{
public:
    Env(
        char* _mySqlHost,
        char* _mySqlPort,
        char* _mySqlUser,
        char* _mySqlPassword,
        char* _appHost,
        char* _appPort
    );
    ~Env();
    
    char* get_mysql_host();
    char* get_mysql_port();
    char* get_mysql_user();
    char* get_mysql_password();
    char* get_app_host();
    char* get_app_port();

private:
    char* mySqlHost;
    char* mySqlPort;
    char* mySqlUser;
    char* mysqlPassword;
    char* appHost;
    char* appPort;
};

#endif /* __ENV_H__ */