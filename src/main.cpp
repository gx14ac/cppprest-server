// Copyright © 2019 netSk8ight. All Rights Reserved. 

#include "handler.hpp"
#include "mysql.hpp"

#include <memory>

std::unique_ptr<Handler> handler;
std::shared_ptr<MySql> db;

static const std::string url = "tcp://127.0.0.1:3306";
static const std::string user = "shinta";
static const std::string password = "";

void startup_handler(const utility::string_t& address)
{
    uri_builder uri(address);
    uri.append_path(U("api/v1/"));

    auto addr = uri.to_uri().to_string();
	handler = std::unique_ptr<Handler>(new Handler(addr));

	handler->open().wait();
    
    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

    return;
}

void shutdown_handler()
{
	handler->close().wait();
    return;
}

void startup_db()
{
    db = std::shared_ptr<MySql>(new MySql(url, user, password));
    if(db->connect_db()) {
        return;
    } else {
        std::cout << "Cannot Open the MySQL DataBase..." << '\n';
        std::cout << "Forced Termination..." << '\n';
        exit(1);
        return;
    }
}

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
}

int main()
{
    utility::string_t port = U("8080");
    utility::string_t address = U("http://localhost:");
    address.append(port);
    startup_db();
    startup_handler(address);

    std::cout << "Press ENTER to exit." << std::endl;
    std::string line;
    std::getline(std::cin, line);

    shutdown_handler();
    shutdown_db();
    return 0;
}