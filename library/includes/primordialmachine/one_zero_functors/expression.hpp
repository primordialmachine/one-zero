#pragma once

#include <sstream>
#include <type_traits>

namespace primordialmachine {

template<bool C, typename T = void>
using enable_if = std::enable_if_t<C, T>;

} // namespace primordialmachine

namespace primordialmachine {

// Test if the types of two expressions are the same.
template<typename A, typename B>
constexpr bool are_same_v = std::is_same_v<A, B>;

struct _is_expression
{};

struct expression : public _is_expression
{}; // struct expression
// Test if a type is an expression type.
template<typename T>
constexpr bool is_expression_v = std::is_base_of_v<_is_expression, T>;

} // namespace primordialmachine

namespace primordialmachine {

struct error_expression : public expression
{}; // struct error_expression
template<typename T>
static constexpr bool is_error_expression_v =
  std::is_base_of_v<error_expression, T>;

} // namespace primordialmachine

namespace primordialmachine {

template<typename EXPRESSION>
using left_operand = typename EXPRESSION::left_operand;

template<typename EXPRESSION>
using right_operand = typename EXPRESSION::right_operand;

template<typename EXPRESSION>
using operand = typename EXPRESSION::operand;

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
struct binary_expression
{
  using left_operand = LEFT_OPERAND;  // access via EXPRESSION::left_operand
  using right_opeand = RIGHT_OPERAND; // access via EXPRESSION::right_operand
};

template<typename OPERAND>
struct unary_expression
{
  using operand = OPERAND; // access via EXPRESSION::operand
};

} // namespace primordialmachine

namespace primordialmachine {

struct _is_add_expression
{};
template<typename EXPRESSION>
constexpr bool is_add_expression_v =
  std::is_base_of_v<_is_add_expression, EXPRESSION>;

template<typename A, typename B>
struct add_expression_impl_2
  : public binary_expression<A, B>
  , public _is_add_expression
{
  using left_operand = A;
  using right_operand = B;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "(" << left_operand::to_string() << ")"
       << "+"
       << "(" << right_operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_add_expression;

template<typename A, typename B>
using add_expression =
  typename evaluate_add_expression<add_expression_impl_2<A, B>>::type;
}

namespace primordialmachine {

struct _is_multiply_expression
{};
template<typename EXPRESSION>
constexpr bool is_multiply_expression_v =
  std::is_base_of_v<_is_multiply_expression, EXPRESSION>;

template<typename A, typename B>
struct multiply_expression_impl_2
  : public binary_expression<A, B>
  , public _is_multiply_expression
{
  using left_operand = A;
  using right_operand = B;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "(" << left_operand::to_string() << ")"
       << "*"
       << "(" << right_operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_multiply_expression;

template<typename A, typename B>
using multiply_expression =
  typename evaluate_multiply_expression<multiply_expression_impl_2<A, B>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct _is_subtract_expression
{};
template<typename EXPRESSION>
constexpr bool is_subtract_expression_v =
  std::is_base_of<_is_subtract_expression, EXPRESSION>;

template<typename A, typename B>
struct subtract_expression_impl_2
  : public binary_expression<A, B>
  , public _is_subtract_expression
{
  using left_operand = A;
  using right_operand = B;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "(" << left_operand::to_string() << ")"
       << "-"
       << "(" << right_operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_subtract_expression;

template<typename A, typename B>
using subtract_expression =
  typename evaluate_subtract_expression<subtract_expression_impl_2<A, B>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct _is_negate_expression
{};
template<typename EXPRESSION>
constexpr bool is_negate_expression_v =
  std::is_base_of<_is_negate_expression, EXPRESSION>::value;

template<typename A>
struct negate_expression_impl_2
  : public unary_expression<A>
  , public _is_negate_expression
{
  using operand = A;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "-(" << operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_negate_expression;

template<typename A>
using negate_expression =
  typename evaluate_negate_expression<negate_expression_impl_2<A>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct _is_affirmate_expression
{};
template<typename EXPRESSION>
constexpr bool is_affirmate_expression_v =
  std::is_base_of<_is_affirmate_expression, EXPRESSION>::value;

template<typename A>
struct affirmate_expression_impl_2
  : public unary_expression<A>
  , public _is_affirmate_expression
{
  using operand = A;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "+(" << operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_affirmate_expression;

template<typename A>
using affirmate_expression =
  typename evaluate_affirmate_expression<affirmate_expression_impl_2<A>>::type;

} // namespace primordialmachine
