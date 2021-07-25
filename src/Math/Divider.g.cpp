// Divider.g.cpp
#include <myproject/Math/Divider.h>

#include <gtest/gtest.h>

namespace myproject {
namespace Math {

using namespace ::testing;

TEST(DividerTest, HasIdentityElement)
{
    // GIVEN
    int lhs = 5;
    int rhs = 1;

    // WHEN
    std::optional<Divider::Result> maybeResult = Divider::forTwoInts(lhs, rhs);

    // THEN
    ASSERT_TRUE(maybeResult.has_value());

    const Divider::Result& result = *maybeResult;
    EXPECT_EQ(lhs, result.d_quotient);
    EXPECT_EQ(0, result.d_remainder);
}

TEST(DividerTest, QuotientIsZeroWhenAbsLhsLessThanAbsRhs)
{
    // GIVEN
    int lhs = 5;
    int rhs = 10;

    // WHEN
    std::optional<Divider::Result> maybeResult = Divider::forTwoInts(lhs, rhs);

    // THEN
    ASSERT_TRUE(maybeResult.has_value());

    const Divider::Result& result = *maybeResult;
    EXPECT_EQ(0, result.d_quotient);
    EXPECT_EQ(5, result.d_remainder);
}

TEST(DividerTest, RemainderIsZeroWhenLhsDivisibleByRhs)
{
    // GIVEN
    int lhs = 10;
    int rhs = 5;

    // WHEN
    std::optional<Divider::Result> maybeResult = Divider::forTwoInts(lhs, rhs);

    // THEN
    ASSERT_TRUE(maybeResult.has_value());

    const Divider::Result& result = *maybeResult;
    EXPECT_EQ(2, result.d_quotient);
    EXPECT_EQ(0, result.d_remainder);
}

TEST(DividerTest, ReturnsNothingWhenDividingByZero)
{
    // GIVEN
    int lhs = 5;
    int rhs = 0;

    // WHEN
    std::optional<Divider::Result> maybeResult = Divider::forTwoInts(lhs, rhs);

    // THEN
    ASSERT_FALSE(maybeResult.has_value());
}

TEST(DividerTest, ReturnsNegQuotientAndPosRemainderWhenEitherOperandIsNegative)
{
    // LHS negative operand

    {
        // GIVEN
        int lhs = 11;
        int rhs = -4;

        // WHEN
        std::optional<Divider::Result> maybeResult = Divider::forTwoInts(lhs, rhs);

        // THEN
        ASSERT_TRUE(maybeResult.has_value());

        const Divider::Result& result = *maybeResult;
        EXPECT_EQ(-2, result.d_quotient);
        EXPECT_EQ(3, result.d_remainder);
    }

    // RHS negative operand

    {
        // GIVEN
        int lhs = -11;
        int rhs = 4;

        // WHEN
        std::optional<Divider::Result> maybeResult = Divider::forTwoInts(lhs, rhs);

        // THEN
        ASSERT_TRUE(maybeResult.has_value());

        const Divider::Result& result = *maybeResult;
        EXPECT_EQ(-2, result.d_quotient);
        EXPECT_EQ(3, result.d_remainder);
    }
}

TEST(DividerTest, ReturnsPosQuotientAndPosRemainderWhenBothOperandsHaveSameSign)
{
    // LHS and RHS are positive

    {
        // GIVEN
        int lhs = 11;
        int rhs = 4;

        // WHEN
        std::optional<Divider::Result> maybeResult = Divider::forTwoInts(lhs, rhs);

        // THEN
        ASSERT_TRUE(maybeResult.has_value());

        const Divider::Result& result = *maybeResult;
        EXPECT_EQ(2, result.d_quotient);
        EXPECT_EQ(3, result.d_remainder);
    }

    // LHS and RHS are negative

    {
        // GIVEN
        int lhs = -11;
        int rhs = -4;

        // WHEN
        std::optional<Divider::Result> maybeResult = Divider::forTwoInts(lhs, rhs);

        // THEN
        ASSERT_TRUE(maybeResult.has_value());

        const Divider::Result& result = *maybeResult;
        EXPECT_EQ(2, result.d_quotient);
        EXPECT_EQ(3, result.d_remainder);
    }

}

}   // closing namespace Math
}   // closing namespace myproject

// ----------------------------------------------------------------------------
// Copyright (c) 2021 Anson Miu
//
// Licensed under the MIT License.
// ----------------------------------------------------------------------------