#pragma once

#include <stdint.h>

namespace primordialmachine::helper {

// value is true if X + Y would positive overflow, false otherwise.
template<int32_t X, int32_t Y>
struct is_additive_positive_overflow_implementation
{
  static constexpr int64_t Z = (int64_t)X + (int64_t)Y;
  static constexpr bool value = Z > (int64_t)INT32_MAX;
}; // struct is_additive_positive_overflow_implementation

template<int32_t X, int32_t Y>
constexpr bool is_additive_positive_overflow =
  is_additive_positive_overflow_implementation<X, Y>::value;

// value is true if X + Y would negative overflow, false otherwise.
template<int32_t X, int32_t Y>
struct is_additive_negative_overflow_implementation
{
  static constexpr int64_t Z = (int64_t)X + (int64_t)Y;
  static constexpr bool value = Z < (int64_t)INT32_MIN;
}; // struct is_additive_negative_overflow_implementation

template<int32_t X, int32_t Y>
constexpr bool is_additive_negative_overflow =
  is_additive_negative_overflow_implementation<X, Y>::value;

template<int32_t X, int32_t Y>
constexpr bool is_additive_overflow =
  is_additive_positive_overflow<X, Y> or is_additive_negative_overflow<X, Y>;

} // namespace primordialmachine::helper

namespace primordialmachine::helper {

// value is true if X - Y would positive overflow, false otherwise.
template<int32_t X, int32_t Y>
struct is_subtractive_positive_overflow_implementation
{
  static constexpr int64_t Z = (int64_t)X - (int64_t)Y;
  static constexpr bool value = Z > (int64_t)INT32_MAX;
}; // struct is_subtractive_positive_overflow_implementation

template<int32_t X, int32_t Y>
constexpr bool is_subtractive_positive_overflow =
  is_subtractive_positive_overflow_implementation<X, Y>::value;

// value is true if X - Y would negative overflow, false otherwise.
template<int32_t X, int32_t Y>
struct is_subtractive_negative_overflow_implementation
{
  static constexpr int64_t Z = (int64_t)X - (int64_t)Y;
  static constexpr bool value = Z < (int64_t)INT32_MIN;
}; // struct is_subtractive_negative_overflow_implementation

template<int32_t X, int32_t Y>
constexpr bool is_subtractive_negative_overflow =
  is_subtractive_negative_overflow_implementation<X, Y>::value;

template<int32_t X, int32_t Y>
constexpr bool is_subtractive_overflow =
  is_subtractive_positive_overflow<X, Y> or
  is_subtractive_negative_overflow<X, Y>;

} // namespace primordialmachine::helper

namespace primordialmachine::helper {

// value is true if X - Y would positive overflow, false otherwise.
template<int32_t X, int32_t Y>
struct is_multiplicative_positive_overflow_implementation
{
  static constexpr int64_t Z = (int64_t)X * (int64_t)Y;
  static constexpr bool value = Z > (int64_t)INT32_MAX;
}; // struct is_multiplicativ_positive_overflow_implementation

template<int32_t X, int32_t Y>
constexpr bool is_multiplicative_positive_overflow =
  is_multiplicative_positive_overflow_implementation<X, Y>::value;

// value is true if X - Y would negative overflow, false otherwise.
template<int32_t X, int32_t Y>
struct is_multiplicative_negative_overflow_implementation
{
  static constexpr int64_t Z = (int64_t)X * (int64_t)Y;
  static constexpr bool value = Z < (int64_t)INT32_MIN;
}; // struct is_multipliactive_negative_overflow_implementation

template<int32_t X, int32_t Y>
constexpr bool is_multiplicative_negative_overflow =
  is_multiplicative_negative_overflow_implementation<X, Y>::value;

template<int32_t X, int32_t Y>
constexpr bool is_multiplicative_overflow =
  is_multiplicative_positive_overflow<X, Y> or
  is_multiplicative_negative_overflow<X, Y>;

} // namespace primordialmachine::helper

namespace primordialmachine::helper {

} // namespace primordialmachine::helper
