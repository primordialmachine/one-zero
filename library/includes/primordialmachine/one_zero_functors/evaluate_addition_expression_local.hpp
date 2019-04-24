/*All local evaluation rules for add expressions.*/
#pragma once

#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

// addition(a, zero) -> a
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_expression_v<left_operand<EXPRESSION>> &&
            is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = left_operand<EXPRESSION>;
};

// addition(zero, a) -> a
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_zero_expression_v<left_operand<EXPRESSION>> &&
            !is_zero_expression_v<right_operand<EXPRESSION>> &&
            is_expression_v<right_operand<EXPRESSION>>>>
{
  using type = right_operand<EXPRESSION>;
};

// addition(error, error) -> error
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<left_operand<EXPRESSION>> &&
            is_error_expression_v<right_operand<EXPRESSION>>>>
{
  using type = error_expression;
};

// addition(a, b) -> addition(b, a)
// a in EXPRESSION - ZERO
// b in VARIABLE
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<(
    !is_zero_expression_v<left_operand<EXPRESSION>> &&
    is_constant_expression_v<left_operand<
      EXPRESSION>>)&&is_variable_expression_v<right_operand<EXPRESSION>>>>
{
  using type = swap<EXPRESSION>;
}; // struct evaluate_addition_expression

// addition(a, b) -> addition(b, a)
// a in VARIABLE
// b in INTEGER
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_variable_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  using type = EXPRESSION;
}; // struct evaluate_addition_expression

// addition(a, a) -> multiplication(a, integer(2))
// a in VARIABLE
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<
    are_same_variable_v<left_operand<EXPRESSION>, right_operand<EXPRESSION>>>>
{
  // TODO: Should not use multiplication_expression_impl_2 but multiplication_expression.
  using type =
    multiplication_expression_impl_2<left_operand<EXPRESSION>, integer_expression<2>>;
}; // struct evaluate_addition_expression

} // namespace primordialmachine
