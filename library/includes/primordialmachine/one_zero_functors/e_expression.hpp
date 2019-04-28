#pragma once

#include "primordialmachine/one_zero_functors/variable_expression.hpp"

namespace primordialmachine {
namespace tag {
struct e_expression
{};
} // namespace tag
template<typename A>
constexpr bool is_e_expression_v = has_tag<A, tag::e_expression>();

struct e_expression
  : public variable_expression
  , public tag::e_expression
{
  static std::string to_string() { return "[e]"; }
}; // struct e_expression

} // namespace primordialmachine
