// Copyright © 2019 netSk8ight. All Rights Reserved. 

#include "handler.hpp"
#include "mysql.hpp"
#include "config.hpp"

#include <memory>

std::unique_ptr<Handler> handler;
std::shared_ptr<MySql> db;

void startup_handler(std::shared_ptr<Env> env)
{
    utility::string_t port = U(env->get_app_port());
    utility::string_t address = U(env->get_app_host());
    address.append(port);
    uri_builder uri(address);
    uri.append_path(U("api/v1/"));

    auto addr = uri.to_uri().to_string();
	handler = std::unique_ptr<Handler>(new Handler(addr));

	handler->open().wait();
    
    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

    return;
};

void shutdown_handler()
{
	handler->close().wait();
    return;
};

void startup_db(std::shared_ptr<Env> env)
{
    db = std::shared_ptr<MySql>(new MySql(env->get_mysql_host(), env->get_mysql_user(), env->get_mysql_password()));
    if(db->connect_db()) {
        return;
    } else {
        std::cout << "Cannot Open the MySQL DataBase..." << '\n';
        std::cout << "Forced Termination..." << '\n';
        exit(1);
        return;
    }
};

void shutdown_db()
{
    if (db->shutdown_db()) {
        return;        
    } else {
        std::cout << "Cannot Close The Database..." << '\n';
        std::cout << "Forced Termination..." << '\n';
        exit(1);
        return;
    }
};

int main()
{
    Config conf;
    startup_db(conf.get_env());
    startup_handler(conf.get_env());

    std::cout << "Press ENTER to exit." << std::endl;
    std::string line;
    std::getline(std::cin, line);

    shutdown_handler();
    shutdown_db();

    return 0;
};