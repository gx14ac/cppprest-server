// Copyright © 2019 netSk8ight. All Rights Reserved. 

#include "config.hpp"

using namespace std;

Config::Config()
{
    env = std::shared_ptr<Env>(
        new Env(
            std::getenv("MYSQL_HOST"),
            std::getenv("MYSQL_PORT"),
            std::getenv("MYSQL_USER"),
            std::getenv("MYSQL_PASSWORD"),
            std::getenv("APP_HOST"),
            std::getenv("APP_PORT")
        )
    );
};

Config::~Config()
{
    std::cout << "destruct Config" << '\n';
};

std::shared_ptr<Env> Config::get_env()
{
    return env;
};
