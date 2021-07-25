// Divider.h
#ifndef INCLUDED_MYPROJECT_MATH_DIVIDER_H
#define INCLUDED_MYPROJECT_MATH_DIVIDER_H

#include <optional>

namespace myproject {
namespace Math {

                               // ==============
                               // struct Divider
                               // ==============

struct Divider {
  public:
    // TYPES
    struct Result {
        int d_quotient;
        int d_remainder;
    };

    // CLASS METHODS
    static std::optional<Result> forTwoInts(int lhs, int rhs);
        // Divides the specified 'lhs' by the specified 'rhs'.  Returns the
        // quotient and remainder, otherwise a 'std::nullopt' if 'rhs' is 0.
};

}   // closing namespace Math
}   // closing namespace myproject

#endif

// ----------------------------------------------------------------------------
// Copyright (c) 2021 Anson Miu
//
// Licensed under the MIT License.
// ----------------------------------------------------------------------------
