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

namespace primordialmachine {

// value is true if X and Y are integer expressions with a common factor greater
// than 1.
template<typename X, typename Y, typename E = void>
struct have_common_factors
{
  static constexpr bool value = false;
};

template<int x, int y>
struct have_common_factors<integer_expression_implementation<x>,
                           integer_expression_implementation<y>,
                           enable_if<(x > 0) && (y > 0)>>
{
  static constexpr bool value = (1 < gcd<x, y>());
};

//
// fraction(multiply(e, i / gcd(i, j)), multiply(f, j/gcd(i,j)))

// fraction(multiply(e, i), j) -> fraction(multiply(e, i / c), j /c)
// c = gcd(i, j)
template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  std::enable_if_t<
    is_multiplication_expression_v<nominator<EXPRESSION>> &&
    is_integer_expression_v<right_operand<nominator<EXPRESSION>>> &&
    is_integer_expression_v<denominator<EXPRESSION>> &&
    have_common_factors<right_operand<nominator<EXPRESSION>>,
                        denominator<EXPRESSION>>::value>>
{
  using nominator_old = nominator<EXPRESSION>;
  using denominator_old = denominator<EXPRESSION>;
  static constexpr int gcd =
    gcd<right_operand<nominator_old>::value, denominator_old::value>();
  using nominator_new = multiplication_expression<
    left_operand<nominator_old>,
    integer_expression<right_operand<nominator_old>::value / gcd>>;
  using denominator_new = integer_expression<denominator_old::value / gcd>;
  using type = fraction_expression_implementation<nominator_new, denominator_new>;
};

// fraction(i, multiply(e, j)) -> fraction(i / c,  multiply(e, j / c)),
// c = gcd(i,j)
template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  std::enable_if_t<
    is_integer_expression_v<nominator<EXPRESSION>> &&
    is_multiplication_expression_v<denominator<EXPRESSION>> &&
    is_integer_expression_v<right_operand<denominator<EXPRESSION>>> &&
    have_common_factors<nominator<EXPRESSION>,
                        right_operand<denominator<EXPRESSION>>>::value>>
{
  using nominator_old = nominator<EXPRESSION>;
  using denominator_old = denominator<EXPRESSION>;
  static constexpr int gcd =
    gcd<nominator_old::value, right_operand<denominator_old>::value>();
  using nominator_new = integer_expression<nominator_old::value / gcd>;
  using denominator_new = multiplication_expression<
    left_operand<denominator_old>,
    integer_expression<right_operand<denominator_old>::value / gcd>>;
  using type = fraction_expression_implementation<nominator_new, denominator_new>;
};

} // namespace primordialmachine

TEST(one_zero_functor_tests, test_degrees_to_radians)
{
  using namespace primordialmachine;
  std::string str;

  using a = multiplication_expression<integer_expression<2>, pi_expression>;
  str = a::to_string();
  std::cout << str << std::endl;

  using b = integer_expression<360>;
  str = b::to_string();
  std::cout << str << std::endl;

  using c = fraction_expression<a, b>;
  str = c::to_string();
  std::cout << str << std::endl;

  using d = fraction_expression<pi_expression, integer_expression<180>>;
  str = d::to_string();
  std::cout << str << std::endl;

  static_assert(are_same_v<d, c>,
                "failed: fraction(multiply(integer(2), pi), integer(360)) -> "
                "fraction(pi, integer(180))");
}

TEST(one_zero_functor_tests, test_radians_to_degrees)
{
  using namespace primordialmachine;
  std::string str;

  using a = integer_expression<360>;
  str = a::to_string();
  std::cout << str << std::endl;

  using b = multiplication_expression<integer_expression<2>, pi_expression>;
  str = b::to_string();
  std::cout << str << std::endl;

  using c = fraction_expression<a, b>;
  str = c::to_string();
  std::cout << str << std::endl;

  using d = fraction_expression<integer_expression<180>, pi_expression>;
  str = d::to_string();
  std::cout << str << std::endl;

  static_assert(are_same_v<d, c>,
                "failed: fraction(integer(360),multiply(integer(2),pi)) -> "
                "fraction(integer(180), pi)");
}

TEST(one_zero_functor_tests, test_canonicalize_1)
{
  using namespace primordialmachine;
  // (V0 + C0) + (V1 + C1) -> (V0 + V1) + (C0 + C1)
  using a = addition_expression<pi_expression, integer_expression<7>>;
  static_assert(
    are_same_v<addition_expression<pi_expression, integer_expression<7>>, a>,
    "failed: addition(pi, integer(7)) -> addition(pi, integer(7))");
  using b = addition_expression<pi_expression, integer_expression<5>>;
  static_assert(
    are_same_v<addition_expression<pi_expression, integer_expression<5>>, b>,
    "failed: addition(pi, integer(5)) -> addition(pi, integer(5))");
  using c = addition_expression<a, b>;
  static_assert(
    is_addition_expression_v<c>,
    "failed: (pi + integer(7)) + (pi + integer(5)) -> (pi * 2) + integer(12)");
  static_assert(
    are_same_v<left_operand<c>,
               multiplication_expression<pi_expression, integer_expression<2>>>,
    "failed: (pi + integer(7)) + (pi + integer(5)) -> (pi * 2) + integer(12)");
  static_assert(
    are_same_v<right_operand<c>, integer_expression<12>>,
    "failed: (pi + integer(7)) + (pi + integer(5)) -> (pi * 2) + integer(12)");
}

TEST(one_zero_functor_tests, test_canonicalize_2)
{
  using namespace primordialmachine;
  // (V0 + C0) - (V1 + C1) -> (V0 - V1) + (C0 - C1)
  using a = addition_expression<pi_expression, integer_expression<7>>;
  static_assert(
    are_same_v<addition_expression<pi_expression, integer_expression<7>>, a>,
    "failed: addition(pi, integer(7)) -> addition(pi, integer(7))");
  using b = addition_expression<pi_expression, integer_expression<5>>;
  static_assert(
    are_same_v<addition_expression<pi_expression, integer_expression<5>>, b>,
    "failed: addition(pi, integer(5)) -> addition(pi, integer(5))");
  using c = subtraction_expression<a, b>;
  static_assert(are_same_v<c, integer_expression<2>>, "error");
}

TEST(one_zero_functor_tests, test_terminal_expressions)
{
  using namespace primordialmachine;
  /*addition([pi], [e]) -> addition([pi], [e])*/
  static_assert(are_same_v<addition_expression<pi_expression, e_expression>,
                           addition_expression<pi_expression, e_expression>>,
                "failed: addition([pi], [e]) -> addition([pi], [e]");
  /*multiplication([pi], [e]) -> multiplication([pi], [e])*/
  static_assert(
    are_same_v<multiplication_expression<pi_expression, e_expression>,
               multiplication_expression<pi_expression, e_expression>>,
    "failed: multiplication([pi], [e]) -> multiplication([pi], [e])");
}

TEST(one_zero_functor_tests, test_zero_expressions)
{
  using namespace primordialmachine;
  // addition(zero, zero) -> zero
  static_assert(
    is_zero_expression_v<addition_expression<zero_expression, zero_expression>>,
    "failed: addition(zero, zero) -> zero");
  // subtraction(zero, zero) -> zero
  static_assert(
    is_zero_expression_v<subtraction_expression<zero_expression, zero_expression>>,
    "failed: subtraction(zero, zero) -> zero");
  // multiplication(zero, zero) -> zero
  static_assert(
    is_zero_expression_v<multiplication_expression<zero_expression, zero_expression>>,
    "failed: multiplication(zero, zero) -> zero");
}

TEST(one_zero_functor_tests, test_one_expressions)
{
  using namespace primordialmachine;
  // multiplication(one, one) -> one
  static_assert(
    is_one_expression_v<multiplication_expression<one_expression, one_expression>>,
    "failed: multiplication(one, one) -> one");
  // subtraction(one, zero) -> one
  static_assert(
    is_one_expression_v<subtraction_expression<one_expression, zero_expression>>,
    "failed: subtraction(one, zero) -> one");
  // subtraction(one, one) -> zero
  static_assert(
    is_zero_expression_v<subtraction_expression<one_expression, one_expression>>,
    "failed: subtraction(one, one) -> zero");
}

// Performs the following tests:
// c == f
// where c is a literal of type T representing zero and f is the zero functor of
// type T.
TEST(one_zero_functor_tests, zero_functor_test)
{
  using namespace primordialmachine;

  ASSERT_EQ(0, zero_functor<char>()());
  ASSERT_EQ(0, zero_functor<signed char>()());
  ASSERT_EQ(0, zero_functor<unsigned char>()());

  ASSERT_EQ(0, zero_functor<signed short int>()());
  ASSERT_EQ(0, zero_functor<unsigned short int>()());

  ASSERT_EQ(0L, zero_functor<signed long int>()());
  ASSERT_EQ(0UL, zero_functor<unsigned long int>()());

  ASSERT_EQ(0LL, zero_functor<signed long long int>()());
  ASSERT_EQ(0ULL, zero_functor<unsigned long long int>()());

  ASSERT_EQ(INT8_C(0), zero_functor<int8_t>()());
  ASSERT_EQ(UINT8_C(0), zero_functor<uint8_t>()());

  ASSERT_EQ(INT16_C(0), zero_functor<int16_t>()());
  ASSERT_EQ(UINT16_C(0), zero_functor<uint16_t>()());

  ASSERT_EQ(INT32_C(0), zero_functor<int32_t>()());
  ASSERT_EQ(UINT32_C(0), zero_functor<uint32_t>()());

  ASSERT_EQ(UINT64_C(0), zero_functor<uint64_t>()());
  ASSERT_EQ(UINT64_C(0), zero_functor<uint64_t>()());

  ASSERT_FLOAT_EQ(0.F, zero_functor<float>()());
  ASSERT_DOUBLE_EQ(0., zero_functor<double>()());
  ASSERT_DOUBLE_EQ(0.L, zero_functor<long double>()());
}
