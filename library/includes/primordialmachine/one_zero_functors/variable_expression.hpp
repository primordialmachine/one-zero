#pragma once

#include "primordialmachine/one_zero_functors/constant_expression.hpp"
#include "primordialmachine/one_zero_functors/swap_helper.hpp"

namespace primordialmachine {

namespace tag {
struct variable_expression
{};
} // namespace tag

template<typename A>
static constexpr bool is_variable_expression_v =
  has_tag<A, tag::variable_expression>();

struct variable_expression
  : public expression
  , public tag::variable_expression
{}; // struct variable_expression

template<typename A, typename B>
constexpr bool are_same_variable_v = is_variable_expression_v<A>&&
  is_variable_expression_v<B>&& std::is_same_v<A, B>;

// multiplication(a, b) -> multiplication(b, a)
// a in INTEGER, b in VARIABLE
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_integer_expression_v<left_operand<EXPRESSION>> &&
            is_variable_expression_v<right_operand<EXPRESSION>>>>
{
  using type = swap<EXPRESSION>;
}; // struct evaluate_multiplication_expression

// multiplication(a, b) -> multiplication(a, b)
// a in VARIABLE, b in INTEGER
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_variable_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  using type = EXPRESSION;
}; // struct evaluate_multiplication_expression

} // namespace primordialmachine
