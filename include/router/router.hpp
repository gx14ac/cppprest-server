// Copyright © 2019 netSk8ight. All Rights Reserved. 

#ifndef __ROUTER_H__
#define __ROUTER_H__

#include "mysql.hpp"
#include "ping.hpp"
#include "user.hpp"

class Router
{
public:
    Router();
    Router(utility::string_t url);
    ~Router();

    void open();
    void close();

private:
    std::unique_ptr<Ping> ping;
    std::unique_ptr<User> user;
};

#endif /* __ROUTER_H__ */