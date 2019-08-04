// Copyright © 2019 netSk8ight. All Rights Reserved.

#ifndef __MYSQL_H__
#define __MYSQL_H__

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_error.h>
#include <string.h>

using namespace sql;
using namespace std;

class MySql
{
public:
    MySql(
        std::string _url,
        std::string _user,
        std::string _password
    );
    
    sql::Connection* connect_db() noexcept;
    bool shutdown_db() noexcept;

private:
    sql::Connection *conn;
    sql::Driver *driver;
    std::string url;
    std::string user;
    std::string password;
};

#endif /* __MYSQL_H__ */