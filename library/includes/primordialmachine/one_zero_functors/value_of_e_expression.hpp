#pragma once

#include "primordialmachine/one_zero_functors/e_expression.hpp"
#include "primordialmachine/one_zero_functors/value_of_expression.hpp"

namespace primordialmachine {

template<>
struct value_of_expression<float, e_expression, void>
{
  using result_type = float;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept
  {
    return 2.71828182845904523536028747135266249775724709369995F;
  }
}; // struct value_of_expression

template<>
struct value_of_expression<double, e_expression, void>
{
  using result_type = double;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept
  {
    return 2.71828182845904523536028747135266249775724709369995;
  }
}; // struct value_of_expression

template<>
struct value_of_expression<long double, e_expression, void>
{
  using result_type = long double;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept
  {
    return 2.71828182845904523536028747135266249775724709369995L;
  }
}; // struct value_of_expression

} // namespace primordialmachine
