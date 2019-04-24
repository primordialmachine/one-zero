///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's One Zero Functors Library
// Copyright (C) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "primordialmachine/one_zero_functors/include.hpp"
#include <gtest/gtest.h>

TEST(one_zero_functor_tests, test_integer_expression_1)
{
  using namespace primordialmachine;

  // add(integer(INT32_MAX), integer(INT32_MAX)) -> error
  static_assert(
    is_error_expression_v<addition_expression<integer_expression<INT32_MAX>,
                                         integer_expression<INT32_MAX>>>,
    "failed: add(integer(INT32_MAX), integer(INT32_MAX)) -> error");

  // subtract(integer(INT32_MIN), integer(INT32_MAX)) -> error
  static_assert(
    is_error_expression_v<subtraction_expression<integer_expression<INT32_MIN>,
                                              integer_expression<INT32_MAX>>>,
    "failed: subtract(integer(INT32_MIN), integer(INT32_MAX)) -> error");

  // multiply(integer(INT32_MAX), integer(INT32_MAX)) -> error
  static_assert(
    is_error_expression_v<multiplication_expression<integer_expression<INT32_MAX>,
                                              integer_expression<INT32_MAX>>>,
    "failed: multiply(integer(INT32_MAX), integer(INT32_MAX)) -> error");
}

TEST(one_zero_functor_tests, test_integer_expression_2)
{
  using namespace primordialmachine;

  // add(integer(7), integer(5)) -> integer(12)
  static_assert(
    are_same_v<integer_expression<12>,
               addition_expression<integer_expression<7>, integer_expression<5>>>,
    "failed: add(integer(7), integer(5)) -> integer(12)");

  // subtract(integer(7), integer(5)) -> integer(2)
  static_assert(
    are_same_v<
      integer_expression<2>,
      subtraction_expression<integer_expression<7>, integer_expression<5>>>,
    "failed: subtract(integer(7), integer(5)) -> integer(2)");

  // multiply(integer(7), integer(5)) -> integer(35)
  static_assert(
    are_same_v<
      integer_expression<35>,
      multiplication_expression<integer_expression<7>, integer_expression<5>>>,
    "failed: multiply(integer(7), integer(5)) -> integer(35)");
}

TEST(one_zero_functor_tests, test_integer_expression_3)
{
  using namespace primordialmachine;

  // integer(0) + integer(0) -> integer(0)
  static_assert(is_zero_expression_v<
                  addition_expression<integer_expression<0>, integer_expression<0>>>,
                "failed: integer(0) + integer(0) -> zero");
  // integer(1) - integer(1) -> zero
  static_assert(
    is_zero_expression_v<
      subtraction_expression<integer_expression<1>, integer_expression<1>>>,
    "failed: integer(1) - integer(1) -> zero");
  // integer(1) * integer(1) -> integer(1)
  static_assert(
    is_one_expression_v<
      multiplication_expression<integer_expression<1>, integer_expression<1>>>,
    "failed: integer(1) * integer(1) -> integer(1)");
  // integer(INT_MAX) -> integer(INT_MAX)
  static_assert(
    are_same_v<integer_expression<INT_MAX>, integer_expression<INT_MAX>>,
    "failed: integer(INT_MAX) -> integer(INT_MAX)");
  // integer(INT_MIN) -> integer(INT_MIN)
  static_assert(
    are_same_v<integer_expression<INT_MIN>, integer_expression<INT_MIN>>,
    "failed: integer(INT_MIN) -> integer(INT_MIN)");
  // integer(INT_MIN) -> integer(INT_MIN)
  static_assert(are_same_v<integer_expression<INT_MIN>,
                           affirmation_expression<integer_expression<INT_MIN>>>,
                "failed: affirmate(integer(INT_MIN)) -> integer(INT_MIN)");
  
  // negate(integer(INT_MIN)) -> ERROR
  static_assert(
    is_error_expression_v<negation_expression<integer_expression<INT_MIN>>>,
    "failed: negate(integer(INT_MIN)) -> error");
  // negate(integer(INT_MAX)) -> integer(INT_MIN + 1)
  static_assert(are_same_v<integer_expression<INT_MIN + 1>,
                           negation_expression<integer_expression<INT_MAX>>>,
                "failed: negate(integer(INT_MAX)) -> integer(INT_MIN + 1)");
}
