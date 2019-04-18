/*All local evaluation rules for negate expressions.*/
#pragma once

#include "primordialmachine/one_zero_functors/e_expression.hpp"
#include "primordialmachine/one_zero_functors/integer_expression.hpp"

namespace primordialmachine {

// negate(e) -> e, e in ERROR U ZERO
template<typename EXPRESSION>
struct evaluate_negate_expression<
  EXPRESSION,
  enable_if<is_error_expression_v<operand<EXPRESSION>> ||
            is_zero_expression_v<operand<EXPRESSION>>>>
{
  using type = operand<EXPRESSION>;
}; // struct evaluate_negate_expression

// negate(E) -> negate(E), E in { variable }
template<typename EXPRESSION>
struct evaluate_negate_expression<
  EXPRESSION,
  enable_if<is_variable_expression_v<operand<EXPRESSION>>>>
{
  using type = EXPRESSION;
}; // struct evaluate_negate_expression

template<typename EXPRESSION>
struct evaluate_negate_expression<
  EXPRESSION,
  enable_if<is_integer_expression_v<operand<EXPRESSION>> &&
            (operand<EXPRESSION>::value > INT_MIN)>>
{
  using type = integer_expression<-operand<EXPRESSION>::value>;
}; // struct evaluate_negate_expression

// type is error_expression INT_MIN can not be negated without an overflow.
template<typename EXPRESSION>
struct evaluate_negate_expression<
  EXPRESSION,
  enable_if<is_integer_expression_v<operand<EXPRESSION>> &&
            (operand<EXPRESSION>::value == INT_MIN)>>
{
  using type = error_expression;
}; // struct evaluate_negate_expression

} // namespace primordialmachine
