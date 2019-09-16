// Copyright © 2019 netSk8ight. All Rights Reserved. 

#include "router.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

Router::Router(utility::string_t url)
{
    user = std::unique_ptr<User>(
        new User(
            url
        )
    );
    
    ping = std::unique_ptr<Ping>(
        new Ping(
            url
        )
    );
};

Router::~Router()
{
    std::cout << "destruct Router" << '\n';
};

void Router::open()
{
    user->open().wait();
    ping->open().wait();
};

void Router::close()
{
    user->close().wait();
    ping->close().wait();
}
