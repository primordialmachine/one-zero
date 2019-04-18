#pragma once

#include "primordialmachine/one_zero_functors/expression.hpp"
#include "primordialmachine/one_zero_functors/swap_helper.hpp"
#include "primordialmachine/one_zero_functors/variable_expression.hpp"

namespace primordialmachine {

// V + negate(E) -> V - E
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<is_negate_expression_v<right_operand<EXPRESSION>> &&
            is_variable_expression_v<left_operand<EXPRESSION>>>>
{
  using type = subtract_expression<left_operand<EXPRESSION>,
                                   operand<right_operand<EXPRESSION>>>;
};

// negate(E) + V -> V + negate(E)
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<is_negate_expression_v<left_operand<EXPRESSION>> &&
            is_variable_expression_v<right_operand<EXPRESSION>>>>
{
  using type = swap<EXPRESSION>;
}; // struct evaluate_add_expression

} // namespace primordialmachine

namespace primordialmachine {

template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<is_multiply_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  using type = EXPRESSION;
};

// (V0 + C0) + (V1 + C1) -> (V0 + V1) + (C0 + C1)
template<typename EXPRESSION>
struct evaluate_add_expression<
  EXPRESSION,
  enable_if<is_add_expression_v<left_operand<EXPRESSION>> &&
            is_add_expression_v<right_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<left_operand<EXPRESSION>>> &&
            is_integer_expression_v<right_operand<right_operand<EXPRESSION>>>>>
{
  using v0 = left_operand<left_operand<EXPRESSION>>;
  using v1 = left_operand<right_operand<EXPRESSION>>;

  using c0 = right_operand<left_operand<EXPRESSION>>;
  using c1 = right_operand<right_operand<EXPRESSION>>;

  using type = add_expression<add_expression<v0, v1>, add_expression<c0, c1>>;
};

// subtract(add(e0, c0), add(e1, c1))
// -> add(subtract(e0, e1), subtract(c0, c1))
template<typename EXPRESSION>
struct evaluate_subtract_expression<
  EXPRESSION,
  enable_if<is_add_expression_v<left_operand<EXPRESSION>> &&
            is_add_expression_v<right_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<left_operand<EXPRESSION>>> &&
            is_integer_expression_v<right_operand<right_operand<EXPRESSION>>>>>
{
  using e0 = left_operand<left_operand<EXPRESSION>>;
  using e1 = left_operand<right_operand<EXPRESSION>>;

  using c0 = right_operand<left_operand<EXPRESSION>>;
  using c1 = right_operand<right_operand<EXPRESSION>>;

  using type =
    add_expression<subtract_expression<e0, e1>, subtract_expression<c0, c1>>;
};

// fraction(multiply(e0, c0), multiply(e1, c1))
// -> multiply(fraction(e0, e1), fraction(c0, c1))
template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<is_multiply_expression_v<left_operand<EXPRESSION>> &&
            is_multiply_expression_v<right_operand<EXPRESSION>> &&
            is_constant_expression_v<right_operand<left_operand<EXPRESSION>>> &&
            is_constant_expression_v<right_operand<right_operand<EXPRESSION>>>>>
{
  using e0 = left_operand<left_operand<EXPRESSION>>;
  using e1 = left_operand<right_operand<EXPRESSION>>;

  using c0 = right_operand<left_operand<EXPRESSION>>;
  using c1 = right_operand<right_operand<EXPRESSION>>;

  using type = multiply_expression<fraction_expression<e0, e1>,
                                   fraction_expression<c0, c1>>;
};

template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<(is_variable_expression_v<nominator<EXPRESSION>> &&
             is_integer_expression_v<denominator<EXPRESSION>>) ||
            (is_integer_expression_v<nominator<EXPRESSION>> &&
             is_variable_expression_v<denominator<EXPRESSION>>)>>
{
  using type = EXPRESSION;
};

} // namespace primordialmachine
