// Copyright © 2019 netSk8ight. All Rights Reserved. 

#ifndef __PING_H__
#define __PING_H__

#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/http_msg.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>

class Ping
{
public:
    Ping();
    ~Ping();

private:
    void ping_get(web::http::http_request message);
};

#endif /* __PING_H__ */