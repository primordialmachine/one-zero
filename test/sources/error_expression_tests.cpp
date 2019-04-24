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

TEST(one_zero_functor_tests, test_error_expression)
{
  using namespace primordialmachine;

  // add(error, error) -> error
  static_assert(
    is_error_expression_v<addition_expression<error_expression, error_expression>>,
    "failed: add(error, error) -> error");

  // subtract(error, error) -> error
  static_assert(is_error_expression_v<
                  subtraction_expression<error_expression, error_expression>>,
                "failed: subtract(error, error) -> error");

  // multiply(error, error) -> error
  static_assert(is_error_expression_v<
                  multiplication_expression<error_expression, error_expression>>,
                "failed: multiply(error, error) -> error");

  // affirmate(error) -> error
  static_assert(is_error_expression_v<affirmation_expression<error_expression>>,
                "failed: affirmate(error) -> error");
  // negate(error) -> error
  static_assert(is_error_expression_v<negation_expression<error_expression>>,
                "failed: negate(error) -> error");

  // add(error, zero) -> error
  static_assert(
    is_error_expression_v<addition_expression<error_expression, zero_expression>>,
    "failed: add(error, zero) -> error");
  // add(zero, error) -> error
  static_assert(
    is_error_expression_v<addition_expression<zero_expression, error_expression>>,
    "failed: add(zero, error) -> error");

  // multiply(error, zero) -> error
  static_assert(is_error_expression_v<
                  multiplication_expression<error_expression, zero_expression>>,
                "failed: multiply(error, zero) -> error");
  // multiply(zero, error) -> error
  static_assert(is_error_expression_v<
                  multiplication_expression<zero_expression, error_expression>>,
                "failed: multiply(zero, error) -> error");

  // multiply(error, one) -> error
  static_assert(is_error_expression_v<
                  multiplication_expression<error_expression, one_expression>>,
                "failed: multiply(error, one) -> error");
  // multiply(one, error) -> error
  static_assert(is_error_expression_v<
                  multiplication_expression<one_expression, error_expression>>,
                "failed: multiply(one, error) -> error");
}
