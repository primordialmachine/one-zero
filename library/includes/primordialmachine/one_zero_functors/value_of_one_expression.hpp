#pragma once


#include "primordialmachine/one_zero_functors/value_of_expression.hpp"
#include "primordialmachine/one_zero_functors/one_expression.hpp"


namespace primordialmachine {

template<>
struct value_of_expression<char, one_expression>
{
  using result_type = char;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed char, one_expression>
{
  using result_type = signed char;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned char, one_expression>
{
  using result_type = unsigned char;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed short int, one_expression>
{
  using result_type = signed short int;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned short int, one_expression>
{
  using result_type = unsigned short int;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed int, one_expression>
{
  using result_type = signed int;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned int, one_expression>
{
  using result_type = unsigned int;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed long int, one_expression>
{
  using result_type = signed long int;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1L; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned long int, one_expression>
{
  using result_type = unsigned long int;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1UL; }
}; // struct value_of_expression




template<>
struct value_of_expression<signed long long int, one_expression>
{
  using result_type = signed long long int;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1LL; }
}; // struct value_of_expression

template<>
struct value_of_expression<unsigned long long int, one_expression>
{
  using result_type = unsigned long long int;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1ULL; }
}; // struct value_of_expression




template<>
struct value_of_expression<float, one_expression>
{
  using result_type = float;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1.F; };
}; // struct value_of_expression

template<>
struct value_of_expression<double, one_expression>
{
  using result_type = double;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1.; };
}; // struct value_of_expression

template<>
struct value_of_expression<long double, one_expression>
{
  using result_type = long double;
  static constexpr bool is_constexpr = true;
  static constexpr bool is_noexcept = true;
  constexpr result_type operator()() const noexcept { return 1.L; }
}; // struct value_of_expression

} // namespace primordialmachine
