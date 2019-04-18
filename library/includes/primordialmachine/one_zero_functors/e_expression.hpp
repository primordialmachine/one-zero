#pragma once

#include "primordialmachine/one_zero_functors/variable_expression.hpp"

namespace primordialmachine {

struct _is_e_expression
{};

struct e_expression
  : public expression
  , public variable_expression
  , public _is_e_expression
{
  static std::string to_string() { return "e"; }
};

template<typename T>
constexpr bool is_e_expression_v = std::is_base_of<_is_e_expression, T>::value;

} // namespace primordialmachine
