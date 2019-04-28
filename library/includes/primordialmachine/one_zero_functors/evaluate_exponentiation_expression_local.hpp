#pragma once

#include "primordialmachine/one_zero_functors/expression.hpp"

namespace primordialmachine {

// Either base or exponent is an error expression or both are an error
// expression. exponentation(a, b) -> a in ERROR or b in ERROR
template<typename EXPRESSION>
struct evaluate_exponentiation_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<left_operand<EXPRESSION>> or
            is_error_expression_v<right_operand<EXPRESSION>>>>
{
  using type = error_expression;
}; // struct evaluate_exponentiation_expression

// exponentation(e, zero) -> e, e in EXPRESSION - ERROR
template<typename EXPRESSION>
struct evaluate_exponentiation_expression<
  EXPRESSION,
  enable_if<is_expression_v<left_operand<EXPRESSION>> &&
            !is_error_expression_v<left_operand<EXPRESSION>> &&
            is_zero_expression_v<right_operand<EXPRESSION>>>>
{
  using type = one_expression;
}; // struct evaluate_exponentiation_expression

// exponentation(e, 1) -> e, e in EXPRESSION - ERROR
template<typename EXPRESSION>
struct evaluate_exponentiation_expression<
  EXPRESSION,
  enable_if<is_expression_v<left_operand<EXPRESSION>> &&
            !is_error_expression_v<left_operand<EXPRESSION>> &&
            is_one_expression_v<right_operand<EXPRESSION>>>>
{
  using type = left_operand<EXPRESSION>;
}; // struct evaluate_exponentiation_expression

} // namespace primordialmachine

namespace primordialmachine {

// exponentation(a, b) -> exponentiation(a, b) a, b in EXPRESSION - ERROR - ZERO
// - ONE
template<typename EXPRESSION>
struct evaluate_exponentiation_expression<
  EXPRESSION,
  enable_if<(is_expression_v<left_operand<EXPRESSION>> &&
             !has_any_tag<left_operand<EXPRESSION>,
                          error_expression_tag,
                          one_expression_tag,
                          zero_expression_tag>()) &&
            (is_expression_v<right_operand<EXPRESSION>> &&
             !has_any_tag<right_operand<EXPRESSION>,
                          error_expression_tag,
                          one_expression_tag,
                          zero_expression_tag>())>>
{
  using type = EXPRESSION;
}; // struct evaluate_exponentiation_expression

} // namespace primordialmachine