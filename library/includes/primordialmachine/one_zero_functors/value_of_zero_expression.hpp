#pragma once

#include "primordialmachine/one_zero_functors/value_of_expression.hpp"
#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

template<>
struct value_of_expression<char, zero_expression>
{
  using result_type = char;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed char, zero_expression>
{
  using result_type = signed char;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned char, zero_expression>
{
  using result_type = unsigned char;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed short int, zero_expression>
{
  using result_type = signed short int;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned short int, zero_expression>
{
  using result_type = unsigned short int;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed int, zero_expression>
{
  using result_type = signed int;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0; }
}; // struct value_of_expression
template<>

struct value_of_expression<unsigned int, zero_expression>
{
  using result_type = unsigned int;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed long int, zero_expression>
{
  using result_type = signed long int;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0L; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned long int, zero_expression>
{
  using result_type = unsigned long int;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0UL; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed long long int, zero_expression>
{
  using result_type = signed long long int;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0LL; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned long long int, zero_expression>
{
  using result_type = unsigned long long int;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0ULL; }
}; // struct value_of_expression




template<>
struct value_of_expression<float, zero_expression>
{
  using result_type = float;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0.F; }
}; // struct value_of_expression

template<>
struct value_of_expression<double, zero_expression>
{
  using result_type = double;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0.; }
}; // struct value_of_expression

template<>
struct value_of_expression<long double, zero_expression>
{
  using result_type = long double;
  static constexpr bool is_noexcept = true;
  static constexpr bool is_constexpr = true;
  constexpr result_type operator()() const noexcept { return 0.L; }
}; // struct value_of_expression

} // namespace primordialmachine
