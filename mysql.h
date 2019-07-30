#pragma once

class MySql
{
public:
    MySql(char *arg_url, char *arg_user, char *arg_password);

private:
    char url[40];
    char user[40];
    char password[40];
    sql::Connection *conn;
    sql::Connection* connect_db();
    void shutdown_db();
};