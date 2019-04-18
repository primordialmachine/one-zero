/*All local evaluation rules for multiply expressions.*/
#pragma once

#include "primordialmachine/one_zero_functors/one_expression.hpp"
#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

// multiply(one, one) -> one
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<is_one_expression_v<left_operand<EXPRESSION>> &&
            is_one_expression_v<right_operand<EXPRESSION>>>>
{
  using type = one_expression;
}; // struct evaluate_multiply_expression

// multiply(zero, zero) -> zero
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<is_zero_expression_v<left_operand<EXPRESSION>> &&
            is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = zero_expression;
}; // struct evaluate_multiply_expression

// multiply(one, e) -> e, e in EXPRESSION - ONE
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<!is_one_expression_v<right_operand<EXPRESSION>> &&
            is_one_expression_v<left_operand<EXPRESSION>>>>
{
  using type = right_operand<EXPRESSION>;
}; // struct evaluate_multiply_expression

// multiply(e, one) -> e, e in EXPRESSION - ONE
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<!is_one_expression_v<left_operand<EXPRESSION>> &&
            is_one_expression_v<right_operand<EXPRESSION>>>>
{
  using type = left_operand<EXPRESSION>;
}; // struct evaluate_multiply_expression

// multiply(e, zero) -> zero, e in EXPRESSION - ERROR - ZERO
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<(!is_zero_expression_v<left_operand<EXPRESSION>> &&
             !is_error_expression_v<left_operand<EXPRESSION>> &&
             is_expression_v<left_operand<
               EXPRESSION>>)&&is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = zero_expression;
}; // struct evaluate_multiply_expression

// multiply(zero, e) -> zero, e in EXPRESSION - ERROR - ZERO
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<(!is_zero_expression_v<right_operand<EXPRESSION>> &&
             !is_error_expression_v<right_operand<EXPRESSION>> &&
             is_expression_v<right_operand<
               EXPRESSION>>)&&is_zero_expression_v<left_operand<EXPRESSION>>>>
{
  using type = zero_expression;
}; // struct evaluate_multiply_expression

// multiply(zero, error) -> error
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<is_zero_expression_v<left_operand<EXPRESSION>> &&
            is_error_expression_v<right_operand<EXPRESSION>>>>
{
  using type = right_operand<EXPRESSION>;
}; // struct evaluate_multiply_expression

// multiply(error, zero) -> error
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<left_operand<EXPRESSION>> &&
            is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = left_operand<EXPRESSION>;
}; // struct evaluate_multiply_expression

// multiply(error, error) -> error
template<typename EXPRESSION>
struct evaluate_multiply_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<left_operand<EXPRESSION>> &&
            is_error_expression_v<right_operand<EXPRESSION>>>>
{
  using type = error_expression;
}; // struct evaluate_multiply_expression

} // namespace primordialmachine
