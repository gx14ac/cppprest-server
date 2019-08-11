#include "env.hpp"

using namespace std;

Env::Env(
    char* _mySqlHost,
    char* _mySqlPort,
    char* _mySqlUser,
    char* _mySqlPassword,
    char* _appHost,
    char* _appPort
    )
{
    mySqlHost     = _mySqlHost;
    mySqlPort     = _mySqlPort;
    mySqlUser     = _mySqlUser;
    mysqlPassword = _mySqlPassword;
    appHost       = _appHost;
    appPort       = _appPort;
};

Env::~Env()
{
    std::cout << "destruct Env" << '\n';
};

char* Env::get_mysql_host()
{
    return mySqlHost;
};

char* Env::get_mysql_port()
{
    return mySqlPort;
};

char* Env::get_mysql_user()
{
  return mySqlUser;  
};

char* Env::get_mysql_password()
{
  return mysqlPassword;  
};

char* Env::get_app_host()
{
    return appHost;
};

char* Env::get_app_port()
{
    return appPort;
};