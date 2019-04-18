#pragma once

#include "primordialmachine/one_zero_functors/euler_mascheroni_constant_expression.hpp"
#include "primordialmachine/one_zero_functors/value_of_expression.hpp"

namespace primordialmachine {

template<>
struct value_of_expression<float, euler_mascheroni_constant_expression, void>
{
  using result_type = float;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept
  {
    return 3.141592653589793238462643383279502884197169399375105820974944592F;
  }
}; // struct value_of_expression

template<>
struct value_of_expression<double, euler_mascheroni_constant_expression, void>
{
  using result_type = double;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept
  {
    return 3.141592653589793238462643383279502884197169399375105820974944592;
  }
}; // struct value_of_expression

template<>
struct value_of_expression<long double, euler_mascheroni_constant_expression, void>
{
  using result_type = long double;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept
  {
    return 3.141592653589793238462643383279502884197169399375105820974944592L;
  }
}; // struct value_of_expression

} // namespace primordialmachine
