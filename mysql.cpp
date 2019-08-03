// Copyright © 2019 netSk8ight. All Rights Reserved. 

#include "mysql.hpp"

using namespace sql;

MySql::MySql(std::string arg_url, std::string arg_user, std::string arg_password)
{
    url = arg_url;
    user = arg_user;
    password = arg_password;
}

sql::Connection* MySql::connect_db()
{
    sql::Driver *driver;

    try
    {
        driver = get_driver_instance();
        conn = driver->connect(url, user, password);
    }
    catch (sql::SQLException &e)
    {
        std::cout << "Error Description:" << e.what() << std::endl;
        std::cout << "Error Code: " << e.getSQLState() << std::endl;
        exit(1);
    }
    
    return conn;
};

void MySql::shutdown_db()
{
    return;
};