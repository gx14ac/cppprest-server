#include "stdafx.h"
#include "handler.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

std::unique_ptr<Handler> g_http;

static const std::string url = "tcp://127.0.0.1:3306";
static const std::string user = "shinta";
static const std::string password = "djgm257890hujm6nvr54hwe";

void configuration_handler(const utility::string_t& address)
{
    uri_builder uri(address);
    uri.append_path(U("api/v1/"));

    auto addr = uri.to_uri().to_string();
	g_http = std::unique_ptr<Handler>(new Handler(addr));

	g_http->open().wait();
    
    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

    return;
}

void shutdown_handler()
{
	g_http->close().wait();
    return;
}

int main()
{
    utility::string_t port = U("8080");
    utility::string_t address = U("http://localhost:");
    address.append(port);
    configuration_handler(address);
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    shutdown_handler();
    return 0;
}