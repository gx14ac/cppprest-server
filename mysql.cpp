#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_error.h>
#include <string.h>
#include "mysql.h"

MySql::MySql(char *arg_url, char *arg_user, char *arg_password)
{
    strcpy(url, arg_url);
    strcpy(user, arg_user);
    strcpy(password, arg_password);
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