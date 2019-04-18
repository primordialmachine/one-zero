/*All local evaluation rules for add expressions.*/
#pragma once

#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

// add(e, zero) -> e
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<is_expression_v<left_operand<EXPRESSION>> &&
            is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = left_operand<EXPRESSION>;
};

// add(zero, e) -> e
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<is_zero_expression_v<left_operand<EXPRESSION>> &&
            !is_zero_expression_v<right_operand<EXPRESSION>> &&
            is_expression_v<right_operand<EXPRESSION>>>>
{
  using type = right_operand<EXPRESSION>;
};

// add(error, error) -> error
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<left_operand<EXPRESSION>> &&
            is_error_expression_v<right_operand<EXPRESSION>>>>
{
  using type = error_expression;
};

// add(e0, e1) -> add(e1, e0), e0 in EXPRESSION - ZERO, e1 in VARIABLE
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<(
    !is_zero_expression_v<left_operand<EXPRESSION>> &&
    is_constant_expression_v<left_operand<
      EXPRESSION>>)&&is_variable_expression_v<right_operand<EXPRESSION>>>>
{
  using type = add_expression<right_operand<EXPRESSION>,
                              left_operand<EXPRESSION>>; // TODO: Define and use
                                                         // swap_operands.
}; // struct evaluate_add_expression

// add(e0, e1) -> add(e1, e0), e0 in VARIABLE, e1 in INTEGER
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<is_variable_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  using type = EXPRESSION;
}; // struct evaluate_add_expression

// add(v, v) -> multiply(v, 2)
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<
    are_same_variable_v<left_operand<EXPRESSION>, right_operand<EXPRESSION>>>>
{
  using type =
    multiply_expression_impl_2<left_operand<EXPRESSION>, integer_expression<2>>;
}; // struct evaluate_add_expression

} // namespace primordialmachine
