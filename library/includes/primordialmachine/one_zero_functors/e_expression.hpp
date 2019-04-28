#pragma once

#include "primordialmachine/one_zero_functors/variable_expression.hpp"

namespace primordialmachine {

struct e_expression_tag
{};
template<typename A>
constexpr bool is_e_expression_v = has_tag<A, e_expression_tag>();

struct e_expression
  : public variable_expression
  , public e_expression_tag
{
  static std::string to_string() { return "e"; }
}; // struct e_expression

} // namespace primordialmachine
