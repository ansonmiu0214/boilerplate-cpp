// calculator.m.cpp

#include <Calculator.h>

#include <iostream>

using namespace myproject;

int main(int argc, const char **argv)
{
    std::cout << "Hello, world!" << std::endl;

    return apps::Calculator(argc - 1, argv + 1).run();
}

// ----------------------------------------------------------------------------
// Copyright (c) 2021 Anson Miu
//
// Licensed under the MIT License.
// ----------------------------------------------------------------------------