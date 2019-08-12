// Copyright © 2019 netSk8ight. All Rights Reserved. 

#include "mysql.hpp"

using namespace sql;
using namespace std;

MySql::MySql(std::string _url, std::string _user, std::string _password)
{
    url = _url;
    user = _user;
    password = _password;
};

MySql::~MySql()
{
    std::cout << "destruct MySql" << '\n';
};

bool MySql::connect_db() noexcept
{
    try 
    {
        driver = get_driver_instance();
        conn = driver->connect(url, user, password);
        std::cout << "Connection of Datebase Succeeded." << endl;
        return true;
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error Description:" << e.what() << '\n';
        std::cerr << "Error Code: " << e.getSQLState() << '\n';
        return false;
    }
};

bool MySql::shutdown_db() noexcept
{
    try
    {
        conn->close();
        driver->threadEnd();
        return true;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error Description:" << e.what() << '\n';
        return false;
    }
};

sql::Connection* MySql::get_db() noexcept
{
    return conn;   
};