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

// exponentation(a, b) -> exponentiation(a, b)
// a in EXPRESSION - ERROR - ZERO - ONE - EXPONENTIATION
// b in EXPRESSION - ERROR - ZERO - ONE
template<typename EXPRESSION>
struct evaluate_exponentiation_expression<
  EXPRESSION,
  enable_if<(is_expression_v<base<EXPRESSION>> &&
             !has_any_tag<base<EXPRESSION>,
                          tag::exponentiation_expression,
                          tag::error_expression,
                          tag::one_expression,
                          tag::zero_expression>()) &&
            (is_expression_v<exponent<EXPRESSION>> &&
             !has_any_tag<exponent<EXPRESSION>,
                          tag::error_expression,
                          tag::one_expression,
                          tag::zero_expression>())>>
{
  using type = EXPRESSION;
}; // struct evaluate_exponentiation_expression

// exponentiation(exponentation(a, b), c)
// -> exponentiation(a, multiplication(b, c)
// c in EXPRESSION - ERROR - ONE - ZERO
template<typename EXPRESSION>
struct evaluate_exponentiation_expression<
  EXPRESSION,
  enable_if<is_exponentiation_expression_v<base<EXPRESSION>> &&
            !has_any_tag<exponent<EXPRESSION>,
                         tag::error_expression,
                         tag::zero_expression,
                         tag::one_expression>()>>
{
  using exponent_1 = exponent<base<EXPRESSION>>;
  using exponent_2 = exponent<EXPRESSION>;
  using base = base<base<EXPRESSION>>;
  using exponent = multiplication_expression<exponent_1, exponent_2>;
  using type = exponentiation_expression<base, exponent>;
}; // struct evaluate_exponentiation_expression

} // namespace primordialmachine
