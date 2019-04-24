/*All local evaluation rules for affirmate expressions.*/
#pragma once

#include "primordialmachine/one_zero_functors/expression.hpp"

namespace primordialmachine {

// affirmation(a) -> a
template<typename EXPRESSION>
struct evaluate_affirmation_expression<
  EXPRESSION,
  enable_if<is_expression_v<operand<EXPRESSION>>>>
{
  using type = operand<EXPRESSION>;
}; // struct evaluate_affirmation_expression

} // namespace primordialmachine
