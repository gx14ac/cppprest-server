// Copyright © 2019 netSk8ight. All Rights Reserved.

#include "ping.hpp"

using namespace std;
using namespace utility;
using namespace web::http;
using namespace web::http::experimental::listener;

Ping::Ping(utility::string_t url) : m_listener(url.append("/ping"))
{
    m_listener.support(methods::GET, std::bind(&Ping::ping_get, this, std::placeholders::_1));
};

Ping::~Ping()
{
    std::cout << "destruct Ping" << '\n';
};

pplx::task<void> Ping::open()
{
    return m_listener.open();
};

pplx::task<void> Ping::close()
{
    return m_listener.close();
};

void Ping::ping_get(http_request message)
{
    ucout << message.to_string() << '\n';
    message.reply(status_codes::OK);
    ucout << "ping OK" << '\n';
    return;
};
