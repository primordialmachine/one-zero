#pragma once

#include "primordialmachine/one_zero_functors/expression.hpp"
#include "primordialmachine/one_zero_functors/swap_helper.hpp"
#include "primordialmachine/one_zero_functors/variable_expression.hpp"

namespace primordialmachine {

// Distributive law.
// multiplication(a, addition|subtraction(b,c))
// ->
// addition|subtraction(multiplication(a,b),multiplication(a,c))

// addition(a, negation(b)) -> subtraction(a, b)
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_negation_expression_v<right_operand<EXPRESSION>> &&
            is_variable_expression_v<left_operand<EXPRESSION>>>>
{
  using type = subtraction_expression<left_operand<EXPRESSION>,
                                      operand<right_operand<EXPRESSION>>>;
};

// addition(negation(a), b) -> addition(a, negation(b))
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_negation_expression_v<left_operand<EXPRESSION>> &&
            is_variable_expression_v<right_operand<EXPRESSION>>>>
{
  using type = swap<EXPRESSION>;
}; // struct evaluate_addition_expression

} // namespace primordialmachine

namespace primordialmachine {

template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_multiplication_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  using type = EXPRESSION;
}; // struct evaluate_addition_expression

// (V0 + C0) + (V1 + C1) -> (V0 + V1) + (C0 + C1)
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_addition_expression_v<left_operand<EXPRESSION>> &&
            is_addition_expression_v<right_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<left_operand<EXPRESSION>>> &&
            is_integer_expression_v<right_operand<right_operand<EXPRESSION>>>>>
{
  using v0 = left_operand<left_operand<EXPRESSION>>;
  using v1 = left_operand<right_operand<EXPRESSION>>;

  using c0 = right_operand<left_operand<EXPRESSION>>;
  using c1 = right_operand<right_operand<EXPRESSION>>;

  using type = addition_expression<addition_expression<v0, v1>,
                                   addition_expression<c0, c1>>;
}; // struct evaluate_addition_expression

// subtraction(addition(e0, c0), addition(e1, c1))
// -> addition(subtraction(e0, e1), subtraction(c0, c1))
template<typename EXPRESSION>
struct evaluate_subtraction_expression<
  EXPRESSION,
  enable_if<is_addition_expression_v<left_operand<EXPRESSION>> &&
            is_addition_expression_v<right_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<left_operand<EXPRESSION>>> &&
            is_integer_expression_v<right_operand<right_operand<EXPRESSION>>>>>
{
  using e0 = left_operand<left_operand<EXPRESSION>>;
  using e1 = left_operand<right_operand<EXPRESSION>>;

  using c0 = right_operand<left_operand<EXPRESSION>>;
  using c1 = right_operand<right_operand<EXPRESSION>>;

  using type = addition_expression<subtraction_expression<e0, e1>,
                                   subtraction_expression<c0, c1>>;
};

// fraction(multiplication(e0, c0), multiplication(e1, c1))
// -> multiplication(fraction(e0, e1), fraction(c0, c1))
template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<is_multiplication_expression_v<left_operand<EXPRESSION>> &&
            is_multiplication_expression_v<right_operand<EXPRESSION>> &&
            is_constant_expression_v<right_operand<left_operand<EXPRESSION>>> &&
            is_constant_expression_v<right_operand<right_operand<EXPRESSION>>>>>
{
  using e0 = left_operand<left_operand<EXPRESSION>>;
  using e1 = left_operand<right_operand<EXPRESSION>>;

  using c0 = right_operand<left_operand<EXPRESSION>>;
  using c1 = right_operand<right_operand<EXPRESSION>>;

  using type = multiplication_expression<fraction_expression<e0, e1>,
                                         fraction_expression<c0, c1>>;
}; // struct evaluate_fraction_expression

template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<(is_variable_expression_v<nominator<EXPRESSION>> &&
             is_integer_expression_v<denominator<EXPRESSION>>) ||
            (is_integer_expression_v<nominator<EXPRESSION>> &&
             is_variable_expression_v<denominator<EXPRESSION>>)>>
{
  using type = EXPRESSION;
}; // struct evaluate_fraction_expression

// multiplication(exponentation(a, b), exponentiation(a,c)
// -> exponentiation(a, addition(b, c)
// a, b in EXPRESSION - ERROR - ONE - ZERO
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_exponentiation_expression_v<left_operand<EXPRESSION>> &&
            is_exponentiation_expression_v<right_operand<EXPRESSION>> &&
            are_same_v<base<left_operand<EXPRESSION>>,
                       base<right_operand<EXPRESSION>>>>>
{
  using exponent_1 = exponent<left_operand<EXPRESSION>>;
  using exponent_2 = exponent<right_operand<EXPRESSION>>;
  using base = base<left_operand<EXPRESSION>>;
  using exponent = addition_expression<exponent_1, exponent_2>;
  using type = exponentiation_expression<base, exponent>;
}; // struct evaluate_exponentiation_expression

} // namespace primordialmachine
