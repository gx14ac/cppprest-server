// Copyright © 2019 netSk8ight. All Rights Reserved.

#ifndef __MYSQL_H__
#define __MYSQL_H__

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_error.h>
#include <string.h>
#include "mysql.hpp"

using namespace sql;

class MySql
{
public:
    MySql(
        std::string arg_url,
        std::string arg_user,
        std::string arg_password
    );
    
    sql::Connection *conn;
    sql::Connection* connect_db();
    void shutdown_db();

private:
    std::string url;
    std::string user;
    std::string password;
};

#endif /* __MYSQL_H__ */