// Divider.cpp
#include <myproject/Math/Divider.h>

#include <cstdlib>

namespace myproject {
namespace Math {

                               // --------------
                               // struct Divider
                               // --------------

// CLASS METHODS
std::optional<Divider::Result> Divider::forTwoInts(int lhs, int rhs)
{
    if (rhs == 0) {
        return std::nullopt;
    }

    int quotient  = lhs / rhs;
    int remainder = abs(lhs % rhs);

    Result result{quotient, remainder};
    return result;
}

}   // closing namespace Math
}   // closing namespace myproject

// ----------------------------------------------------------------------------
// Copyright (c) 2021 Anson Miu
//
// Licensed under the MIT License.
// ----------------------------------------------------------------------------