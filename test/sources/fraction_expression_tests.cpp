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

TEST(one_zero_functor_tests, test_fraction_expression)
{
  using namespace primordialmachine;

  // fraction(one, one) -> one
  static_assert(
    is_one_expression_v<fraction_expression<one_expression, one_expression>>,
    "failed: fraction(one, one) -> one");

  // fraction(zero, one) -> zero
  static_assert(
    is_zero_expression_v<fraction_expression<zero_expression, one_expression>>,
    "failed: fraction(zero, one) -> zero");

  // fraction(integer(64),integer(64)) -> one
  static_assert(
    is_one_expression_v<
      fraction_expression<integer_expression<64>, integer_expression<64>>>,
    "failed: fraction(integer(64),integer(64)) -> integer(1)");

  // fraction(integer(360),integer(2)) -> integer(180)
  static_assert(
    are_same_v<
      integer_expression<180>,
      fraction_expression<integer_expression<360>, integer_expression<2>>>,
    "failed: fraction(integer(360),integer(2)) -> integer(180)");
}

TEST(one_zero_functor_tests, test_double_fraction_expression)
{
  using namespace primordialmachine;

  // fraction(pi, pi) -> one
  static_assert(
    is_one_expression_v<fraction_expression<pi_expression, pi_expression>>,
    "failed: fraction(pi, pi) -> one");
  // fraction(e, e) -> one
  static_assert(
    is_one_expression_v<fraction_expression<e_expression, e_expression>>,
    "failed: fraction(e, e) -> one");
  // fraction(golden_ratio, golden_ratio) -> one
  static_assert(
    is_one_expression_v<
      fraction_expression<golden_ratio_expression, golden_ratio_expression>>,
    "failed: fraction(golden_ratio, golden_ratio) -> one");
}
