/*All local evaluation rules for affirmate expressions.*/
#pragma once

#include "primordialmachine/one_zero_functors/expression.hpp"

namespace primordialmachine {

// affirmate(E) -> E
template<typename EXPRESSION>
struct evaluate_affirmate_expression<
  EXPRESSION,
  enable_if<is_expression_v<operand<EXPRESSION>>>>
{
  using type = operand<EXPRESSION>;
}; // struct evaluate_affirmate_expression

} // namespace primordialmachine
