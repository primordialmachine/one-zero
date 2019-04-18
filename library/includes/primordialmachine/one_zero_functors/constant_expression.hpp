#pragma once

#include "primordialmachine/one_zero_functors/fraction_expression.hpp"
#include "primordialmachine/one_zero_functors/integer_expression.hpp"
#include "primordialmachine/one_zero_functors/one_expression.hpp"
#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

// constant_expression := one | zero | integer | fraction
template<typename EXPRESSION>
constexpr bool is_constant_expression_v =
  is_one_expression_v<EXPRESSION> || is_zero_expression_v<EXPRESSION> ||
  is_integer_expression_v<EXPRESSION> || is_fraction_expression_v<EXPRESSION>;

} // namespace primordialmachine
