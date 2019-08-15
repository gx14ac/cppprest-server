// Copyright © 2019 netSk8ight. All Rights Reserved.

#include "ping.hpp"

using namespace std;
using namespace utility;
using namespace web;
using namespace http;
using namespace web::http::experimental::listener;

Ping::Ping()
{
    
};

Ping::~Ping()
{
    std::cout << "destruct Ping" << '\n';
};

void Ping::ping_get(web::http::http_request message)
{
    ucout << message.to_string() << endl;
    message.reply(status_codes::OK);
    return;
};
