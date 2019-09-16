// Copyright © 2019 netSk8ight. All Rights Reserved.

#include "user.hpp"

using namespace web::http;
using namespace web::http::experimental::listener;

User::User (utility::string_t url) : m_listener(url.append("/user"))
{
    m_listener.support(methods::GET, std::bind(&User::user_get, this, std::placeholders::_1));
};

User::~User()
{
    std::cout << "destruct User" << '\n';
};

pplx::task<void> User::open()
{
    return m_listener.open();
};

pplx::task<void> User::close()
{
    return m_listener.close();
};

void User::user_get(web::http::http_request message)
{
    ucout << message.to_string() << '\n';
    message.reply(status_codes::OK);
    ucout << "user OK" << '\n';
    return;
};