// Copyright © 2019 netSk8ight. All Rights Reserved. 

#ifndef __ROUTER_H__
#define __ROUTER_H__

#include "mysql.hpp"

#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>

class Router
{
public:
    Router();
    Router(utility::string_t url);
    ~Router();

private:
	web::http::experimental::listener::http_listener m_listener;
};

#endif /* __ROUTER_H__ */