// Copyright © 2019 netSk8ight. All Rights Reserved. 

#include "router.hpp"
#include "mysql.hpp"
#include "config.hpp"

std::unique_ptr<Router> router;
std::shared_ptr<MySql> db;

void open_router(std::shared_ptr<Env> env)
{
    utility::string_t port = U(env->get_app_port());
    utility::string_t address = U(env->get_app_host());
    address.append(port);
    web::uri_builder uri(address);
    uri.append_path(U("api/v1"));

    auto addr = uri.to_uri().to_string();
	router = std::unique_ptr<Router>(new Router(addr));

	router->open();
    
    ucout << utility::string_t(U("Listening for requests at: ")) << addr << '\n';

    return;
};

void close_router()
{
	router->close();
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
    open_router(conf.get_env());

    std::cout << "Press ENTER to exit." << '\n';
    std::string line;
    std::getline(std::cin, line);

    close_router();
    shutdown_db();

    return 0;
};