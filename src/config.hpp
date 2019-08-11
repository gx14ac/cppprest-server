// Copyright © 2019 netSk8ight. All Rights Reserved. 

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "env.hpp"

#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

class Config
{
public:
    Config();
    ~Config();

    std::shared_ptr<Env> get_env();

private:
    std::shared_ptr<Env> env;
};

#endif /* __CONFIG_H__ */
