#include "stdafx.h"
#include "MyServer.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

std::unique_ptr<MyServer> g_http;

static const std::string url = "tcp://127.0.0.1:3306";
static const std::string user = "shinta";
static const std::string password = "djgm257890hujm6nvr54hwe";

void connnect_mysql()
{
    sql::Driver *driver;
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *rs;
    sql::PreparedStatement *prep_stmt;
    
    try
    {
        driver = get_driver_instance();

        conn = driver->connect(url, user, password);

        conn->setSchema("provinces");

        // Statement example
        stmt = conn->createStatement();

        rs = stmt->executeQuery("SELECT * FROM provinces");

        std::cout << "Retreived row count: " << rs->rowsCount() << std::endl;

        for (size_t i = 0; i < rs->rowsCount(); ++i) {
            rs->next();
            std::cout << "Next string: " <<  rs->getString("province") <<  std::endl;
        }

        // Prepared statement example
        prep_stmt = conn->prepareStatement("INSERT INTO provinces (province, population) VALUES (?, ?)");

        prep_stmt->setString(1, "test province");
        prep_stmt->setString(2, "3");

        int update_count = prep_stmt->executeUpdate();

        std::cout << "Updated row count: " << update_count << std::endl;

        delete rs;
        delete stmt;
        delete prep_stmt;
        conn->close();
        delete conn;
    }
    catch (sql::SQLException &e)
    {
        std::cout << "Error Description:" << e.what() << std::endl;
        std::cout << "Error Code: " << e.getSQLState() << std::endl;
    }

    return;
}

void configuration_db(const utility::string_t& address)
{
    uri_builder uri(address);
    uri.append_path(U("api/v1/"));

    auto addr = uri.to_uri().to_string();
	g_http = std::unique_ptr<MyServer>(new MyServer(addr));

	g_http->open().wait();
    
    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

    return;
}

void shutdown_db()
{
	g_http->close().wait();
    return;
}

int main()
{
    utility::string_t port = U("8080");
    utility::string_t address = U("http://localhost:");
    address.append(port);
    connnect_mysql();
    configuration_db(address);
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    shutdown_db();
    return 0;
}