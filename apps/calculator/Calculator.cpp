// Calculator.cpp
#include <Calculator.h>

#include <myproject/Math/Adder.h>

#include <iostream>
#include <stdexcept>
#include <string>

namespace myproject {
namespace apps {

namespace {

bool parseInt(int *output, const char *str)
    // Attempts to parse an integer into the specified 'output' from the
    // string specified by 'str'.  Returns true if the operation was
    // successful, false otherwise. 
{
    try {
        *output = std::stoi(str);
        return true;
    }
    catch (const std::invalid_argument&) {
        return false;
    }
}

}   // closing anonymous namespace 

                              // ================
                              // class Calculator
                              // ================

// CREATORS
Calculator::Calculator(int argc, const char **argv)
: d_argc(argc)
, d_argv(argv)
{
}

// ACCESSORS
int Calculator::run() const
{
    if (d_argc != 3) {
        std::cerr << "Expected 3 arguments, got " << d_argc << std::endl;
        return 1;
    }

    int lhs;
    int rhs;

    if (!parseInt(&lhs, d_argv[1]) || !parseInt(&rhs, d_argv[2])) {
        std::cerr << "Cannot parse one or more operands from: "
                  << "'" << d_argv[1] << "', "
                  << "'" << d_argv[2] << "'"
                  << std::endl;
        return 1;
    }

    std::string operation(d_argv[0]);
    if (operation == "add") {
        std::cout << lhs << " + " << rhs << " = "
                  << Math::Adder::forTwoInts(lhs, rhs)
                  << std::endl;
    }
    else {
        std::cerr << "Unsupported command: '" << operation << "'" << std::endl;
        return 1;
    }

    return 0;
}

}   // closing namespace apps
}   // closing namespace myproject

// ----------------------------------------------------------------------------
// Copyright (c) 2021 Anson Miu
//
// Licensed under the MIT License.
// ----------------------------------------------------------------------------