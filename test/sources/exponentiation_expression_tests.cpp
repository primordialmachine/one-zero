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
#include "variable_expression_test.hpp"
#include <gtest/gtest.h>

TEST(one_zero_functors_tests, test_exponentiation_error_expressions_with_error)
{
  using namespace primordialmachine;
  /*exponentiation(pi, error) = exponentiation(error, pi) -> error*/
  static_assert(is_error_expression_v<
                  exponentiation_expression<pi_expression, error_expression>>,
                "failed: exponentiation(pi, error) -> error");
  static_assert(is_error_expression_v<
                  exponentiation_expression<error_expression, pi_expression>>,
                "failed: exponentiation(pi, error) -> error");
  /*exponentiation(zero, error) = exponentiation(error, zero) -> error*/
  static_assert(is_error_expression_v<
                  exponentiation_expression<zero_expression, error_expression>>,
                "failed: exponentiation(zero, error) -> error");
  static_assert(is_error_expression_v<
                  exponentiation_expression<error_expression, zero_expression>>,
                "failed: exponentiation(error, zero) -> error");
  /*exponentiation(one, error) = exponentiation(error, one) -> error*/
  static_assert(is_error_expression_v<
                  exponentiation_expression<one_expression, error_expression>>,
                "failed: exponentiation(one, error) -> error");
  static_assert(is_error_expression_v<
                  exponentiation_expression<error_expression, one_expression>>,
                "failed: exponentiation(error, one) -> error");
  /*exponentiation(error, error) -> error*/
  static_assert(
    is_error_expression_v<
      exponentiation_expression<error_expression, error_expression>>,
    "failed: exponentiation(error, error) -> error");
}

TEST(one_zero_functors_tests,
     test_exponentiation_expressions_with_zero_exponent)
{
  using namespace primordialmachine;
  /*exponentiation(pi, zero) -> one*/
  static_assert(is_one_expression_v<
                  exponentiation_expression<pi_expression, zero_expression>>,
                "failed: exponentiation(pi, zero) -> one");
  /*exponentiation(zero, zero) -> one*/
  static_assert(is_one_expression_v<
                  exponentiation_expression<zero_expression, zero_expression>>,
                "failed: exponentiation(zero, zero) -> one");
  /*exponentiation(one, zero) -> one*/
  static_assert(is_one_expression_v<
                  exponentiation_expression<one_expression, zero_expression>>,
                "failed: exponentiation(one, zero) -> one");
}

TEST(one_zero_functors_tests, test_exponentiation_expressions_with_one_exponent)
{
  using namespace primordialmachine;
  /*exponentiation(pi, one) -> pi*/
  static_assert(is_pi_expression_v<
                  exponentiation_expression<pi_expression, one_expression>>,
                "failed: exponentiation(pi, one) -> pi");
  /*exponentiation(zero, one) -> zero*/
  static_assert(is_zero_expression_v<
                  exponentiation_expression<zero_expression, one_expression>>,
                "failed: exponentiation(zero, one) -> one");
  /*exponentiation(one, one) -> one*/
  static_assert(is_one_expression_v<
                  exponentiation_expression<one_expression, one_expression>>,
                "failed: exponentiation(one, one) -> one");
}
