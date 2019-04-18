// V * one -> V
//
// C * V -> V * C
// C + V -> V + C
//
// where C in (zero U one U integers U fractions) and V in variables .
#pragma once

#include "primordialmachine/one_zero_functors/constant_expression.hpp"

namespace primordialmachine {

struct _is_variable_expression
{};
template<typename T>
static constexpr bool is_variable_expression_v =
  std::is_base_of<_is_variable_expression, T>::value;

struct variable_expression : public _is_variable_expression
{}; // struct variable_expression

template<typename A, typename B>
constexpr bool are_same_variable_v = is_variable_expression_v<A>&&
  is_variable_expression_v<B>&& std::is_same_v<A, B>;

// multiply(integer, variable) -> multiply(variable, integer)
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<is_integer_expression_v<left_operand<EXPRESSION>> &&
            is_variable_expression_v<right_operand<EXPRESSION>>>>
{
  using type =
    multiply_expression<right_operand<EXPRESSION>,
                        left_operand<EXPRESSION>>; // TODO: Define and use
                                                   // swap_operands.
}; // struct evaluate_multiply_expression

// V * I -> V * I
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<is_variable_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  using type = EXPRESSION;
}; // struct evaluate_multiply_expression

} // namespace primordialmachine
