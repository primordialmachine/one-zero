/*All local evaluation rules for subtract expressions.*/
#pragma once

#include "primordialmachine/one_zero_functors/one_expression.hpp"
#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

// subtract(one, one) -> zero
template<typename EXPRESSION>
struct evaluate_subtract_expression<
  EXPRESSION,
  enable_if<is_one_expression_v<left_operand<EXPRESSION>> &&
            is_one_expression_v<right_operand<EXPRESSION>>>>
{
  using type = zero_expression;
}; // struct evaluate_subtract_expression

// subtract(v, v) -> zero, v in VARIABLES
template<typename EXPRESSION>
struct evaluate_subtract_expression<
  EXPRESSION,
  enable_if<
    are_same_variable_v<left_operand<EXPRESSION>, right_operand<EXPRESSION>>>>
{
  using type = zero_expression;
}; // struct evaluate_subtract_expression

// subtract(e, zero) -> e, e in EXPRESSION
template<typename EXPRESSION>
struct evaluate_subtract_expression<
  EXPRESSION,
  enable_if<is_expression_v<left_operand<EXPRESSION>> &&
            is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = left_operand<EXPRESSION>;
}; // struct evaluate_subtract_expression

// subtract(error, error) -> error
template<typename EXPRESSION>
struct evaluate_subtract_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<left_operand<EXPRESSION>> &&
            is_error_expression_v<right_operand<EXPRESSION>>>>
{
  using type = error_expression;
}; // struct evaluate_subtract_expression

} // namespace primordialmachine
