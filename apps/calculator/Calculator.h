// Calculator.h
#ifndef INCLUDED_CALCULATOR_CALCULATOR_H
#define INCLUDED_CALCULATOR_CALCULATOR_H

namespace myproject {
namespace apps {

                              // ================
                              // class Calculator
                              // ================

class Calculator {
  private:
    // DATA
    int          d_argc;
    const char **d_argv;

  public:
    // CREATORS
    Calculator(int argc, const char **argv);

    // ACCESSORS
    int run() const;
        // Runs the calculator, and returns the exit code.
};

}   // closing namespace apps
}   // closing namespace myproject

#endif

// ----------------------------------------------------------------------------
// Copyright (c) 2021 Anson Miu
//
// Licensed under the MIT License.
// ----------------------------------------------------------------------------