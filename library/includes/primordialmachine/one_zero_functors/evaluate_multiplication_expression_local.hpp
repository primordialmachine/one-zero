/*All local evaluation rules for multiply expressions.*/
#pragma once

#include "primordialmachine/one_zero_functors/one_expression.hpp"
#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

// multiplication(one, one) -> one
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_one_expression_v<left_operand<EXPRESSION>> &&
            is_one_expression_v<right_operand<EXPRESSION>>>>
{
  using type = one_expression;
}; // struct evaluate_multiplication_expression

// multiplication(zero, zero) -> zero
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_zero_expression_v<left_operand<EXPRESSION>> &&
            is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = zero_expression;
}; // struct evaluate_multiplication_expression

// multiplication(one, e) -> e
// e in EXPRESSION - ONE
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<!is_one_expression_v<right_operand<EXPRESSION>> &&
            is_one_expression_v<left_operand<EXPRESSION>>>>
{
  using type = right_operand<EXPRESSION>;
}; // struct evaluate_multiplication_expression

// multiplication(e, one) -> e
// e in EXPRESSION - ONE
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<!is_one_expression_v<left_operand<EXPRESSION>> &&
            is_one_expression_v<right_operand<EXPRESSION>>>>
{
  using type = left_operand<EXPRESSION>;
}; // struct evaluate_multiplication_expression

// multiplication(e, zero) -> zero
// e in EXPRESSION - ERROR - ZERO
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<(!has_any_tag<left_operand<EXPRESSION>,
                          tag::zero_expression,
                          tag::error_expression>() &&
             is_expression_v<left_operand<
               EXPRESSION>>)&&is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = zero_expression;
}; // struct evaluate_multiplication_expression

// multiplication(zero, a) -> zero
// a in EXPRESSION - ERROR - ZERO
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<(!has_any_tag<right_operand<EXPRESSION>,
                          tag::zero_expression,
                          tag::error_expression>() &&
             is_expression_v<right_operand<
               EXPRESSION>>)&&is_zero_expression_v<left_operand<EXPRESSION>>>>
{
  using type = zero_expression;
}; // struct evaluate_multiplication_expression

// multiplication(zero, error) -> error
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_zero_expression_v<left_operand<EXPRESSION>> &&
            is_error_expression_v<right_operand<EXPRESSION>>>>
{
  using type = right_operand<EXPRESSION>;
}; // struct evaluate_multiplication_expression

// multiplication(error, zero) -> error
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<left_operand<EXPRESSION>> &&
            is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = left_operand<EXPRESSION>;
}; // struct evaluate_multiplication_expression

// multiplication(error, error) -> error
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<left_operand<EXPRESSION>> &&
            is_error_expression_v<right_operand<EXPRESSION>>>>
{
  using type = error_expression;
}; // struct evaluate_multiplication_expression

// multiplication(a, b) -> multiplication(a, b)
// a != b, a, b in VARIABLE
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<
    is_variable_expression_v<left_operand<EXPRESSION>> &&
    is_variable_expression_v<right_operand<EXPRESSION>> &&
    !are_same_variable_v<left_operand<EXPRESSION>, right_operand<EXPRESSION>>>>
{
  using type = EXPRESSION;
}; // struct evaluate_multiplication_expression

} // namespace primordialmachine
