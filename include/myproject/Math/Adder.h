// adder.h
#ifndef INCLUDED_MYPROJECT_MATH_ADDER_H
#define INCLUDED_MYPROJECT_MATH_ADDER_H

namespace myproject {
namespace Math {

                                // ============
                                // struct Adder
                                // ============

struct Adder {
  public:
    // CLASS METHODS
    static int forTwoInts(int lhs, int rhs);
        // Returns the sum of the operands specified by 'lhs' and 'rhs'.
};

}   // closing namespace Math
}   // closing namespace myproject

#endif

// ----------------------------------------------------------------------------
// Copyright (c) 2021 Anson Miu
//
// Licensed under the MIT License.
// ----------------------------------------------------------------------------
