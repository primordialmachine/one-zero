// An integer expressions represents an integer.
#pragma once

#include "primordialmachine/one_zero_functors/expression.hpp"
#include "primordialmachine/one_zero_functors/is_overflow_helper.hpp"
#include "primordialmachine/one_zero_functors/one_expression.hpp"
#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

struct _is_integer_expression
{};
// Test if a type is an integer expression type.
template<typename T>
constexpr bool is_integer_expression_v =
  std::is_base_of<_is_integer_expression, T>::value;

// represents values from -MIN to +MAX
template<int VALUE>
struct integer_expression_impl
  : public expression
  , public _is_integer_expression
{
  static constexpr const int32_t value = VALUE;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "integer(" << value << ")";
    return os.str();
  }
}; // struct integer_expression_impl

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_integer_expression;

template<int32_t VALUE>
using integer_expression =
  typename evaluate_integer_expression<integer_expression_impl<VALUE>>::type;

} // namespace primordialmachine

namespace primordialmachine {

// integer(0) -> zero
template<typename EXPRESSION>
struct evaluate_integer_expression<EXPRESSION,
                                   enable_if<EXPRESSION::value == INT32_C(0)>>
{
  using type = zero_expression;
}; // struct evaluate_integer_expression

// integer(1) -> one
template<typename EXPRESSION>
struct evaluate_integer_expression<EXPRESSION,
                                   enable_if<EXPRESSION::value == INT32_C(1)>>
{
  using type = one_expression;
}; // struct evaluate_integer_expression

// integer(x) -> integer(x), x not in { 0, 1 }
template<typename EXPRESSION>
struct evaluate_integer_expression<
  EXPRESSION,
  enable_if<EXPRESSION::value != INT32_C(0) && EXPRESSION::value != INT32_C(1)>>
{
  using type = EXPRESSION;
}; // struct evaluate_integer_expression

// addition(integer(x), integer(y)) -> integer(x + y) if not overflow(+, x, y)
//                                  -> error          otherwise
template<typename EXPRESSION>
struct evaluate_addition_expression<
  EXPRESSION,
  enable_if<is_integer_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  static constexpr const int32_t left_value = left_operand<EXPRESSION>::value;
  static constexpr const int32_t right_value = right_operand<EXPRESSION>::value;
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4307)
#endif
  using type =
    std::conditional_t<!helper::is_additive_overflow<left_value, right_value>,
                       integer_expression<(left_value + right_value)>,
                       error_expression>;
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
}; // struct evaluate_addition_expression

// subtraction(integer(x), integer(y)) -> integer(x - y) if not overflow(-, x, y)
//                                     -> error          otherwise
template<typename EXPRESSION>
struct evaluate_subtraction_expression<
  EXPRESSION,
  enable_if<is_integer_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  static constexpr const int32_t left_value = left_operand<EXPRESSION>::value;
  static constexpr const int32_t right_value = right_operand<EXPRESSION>::value;
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4307)
#endif
  using type = std::conditional_t<
    !helper::is_subtractive_overflow<left_value, right_value>,
    integer_expression<(left_value - right_value)>,
    error_expression>;
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
}; // struct evaluate_subtraction_expression

// multiplication(integer(x), integer(y)) -> integer(x * y) if not overflow(*, x, y)
//                                        -> error otherwise
template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_integer_expression_v<left_operand<EXPRESSION>> &&
            is_integer_expression_v<right_operand<EXPRESSION>>>>
{
  static constexpr const int32_t left_value = left_operand<EXPRESSION>::value;
  static constexpr const int32_t right_value = right_operand<EXPRESSION>::value;
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4307)
#endif
  using type = std::conditional_t<
    !helper::is_multiplicative_overflow<left_value, right_value>,
    integer_expression<(left_value * right_value)>,
    error_expression>;
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
}; // struct evaluate_multiplication_expression

} // namespace primordialmachine
