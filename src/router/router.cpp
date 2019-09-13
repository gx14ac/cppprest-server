// Copyright © 2019 netSk8ight. All Rights Reserved. 

#include "router.hpp"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

Router::Router(utility::string_t url)
{
    ping = std::unique_ptr<Ping>(
        new Ping(
            url.append("/ping")
        )
    );
};

Router::~Router()
{
    std::cout << "destruct Router" << '\n';
};

void Router::open()
{
    ping->open().wait();
};

void Router::close()
{
    ping->close().wait();
}
