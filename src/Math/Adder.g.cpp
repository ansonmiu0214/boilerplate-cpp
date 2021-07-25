// Adder.g.cpp
#include <myproject/Math/Adder.h>

#include <gtest/gtest.h>

namespace myproject {
namespace Math {

using namespace ::testing;

TEST(AdderTest, HasIdentityElement)
{
    // GIVEN
    int lhs = 0;
    int rhs = 5;

    // WHEN
    int sum = Adder::forTwoInts(lhs, rhs);

    // THEN
    EXPECT_EQ(5, sum);
}

TEST(AdderTest, SupportsNegativeOperands)
{
    // LHS negative operand

    {
        // GIVEN
        int lhs = -5;
        int rhs = 10;

        // WHEN
        int sum = Adder::forTwoInts(lhs, rhs);

        // THEN
        EXPECT_EQ(5, sum);
    }

    // RHS negative operand

    {
        // GIVEN
        int lhs = -5;
        int rhs = 10;

        // WHEN
        int sum = Adder::forTwoInts(lhs, rhs);

        // THEN
        EXPECT_EQ(5, sum);
    }
}

TEST(AdderTest, IsCommutative)
{
    // GIVEN
    int lhs = 89;
    int rhs = 64;

    // WHEN
    int lhsPlusRhs = Adder::forTwoInts(lhs, rhs);
    int rhsPlusRhs = Adder::forTwoInts(rhs, lhs);

    // THEN
    EXPECT_EQ(lhsPlusRhs, rhsPlusRhs);
}

}   // closing namespace Math
}   // closing namespace myproject

// ----------------------------------------------------------------------------
// Copyright (c) 2021 Anson Miu
//
// Licensed under the MIT License.
// ----------------------------------------------------------------------------