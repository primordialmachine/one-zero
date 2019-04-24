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

struct _is_addition_expression
{};
template<typename EXPRESSION>
constexpr bool is_addition_expression_v =
  std::is_base_of_v<_is_addition_expression, EXPRESSION>;

template<typename A, typename B>
struct addition_expression_impl_2
  : public binary_expression<A, B>
  , public _is_addition_expression
{
  using left_operand = A;
  using right_operand = B;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "addition(" << left_operand::to_string() << ", "
       << right_operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_addition_expression;

template<typename A, typename B>
using addition_expression =
  typename evaluate_addition_expression<addition_expression_impl_2<A, B>>::type;
}

namespace primordialmachine {

struct _is_multiplication_expression
{};
template<typename EXPRESSION>
constexpr bool is_multiplication_expression_v =
  std::is_base_of_v<_is_multiplication_expression, EXPRESSION>;

template<typename A, typename B>
struct multiplication_expression_impl_2
  : public binary_expression<A, B>
  , public _is_multiplication_expression
{
  using left_operand = A;
  using right_operand = B;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "multiplication(" << left_operand::to_string() << ", "
       << right_operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_multiplication_expression;

template<typename A, typename B>
using multiplication_expression =
  typename evaluate_multiplication_expression<multiplication_expression_impl_2<A, B>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct _is_subtraction_expression
{};
template<typename EXPRESSION>
constexpr bool is_subtraction_expression_v =
  std::is_base_of<_is_subtraction_expression, EXPRESSION>;

template<typename A, typename B>
struct subtraction_expression_impl_2
  : public binary_expression<A, B>
  , public _is_subtraction_expression
{
  using left_operand = A;
  using right_operand = B;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "subtraction(" << left_operand::to_string() << ", "
       << right_operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_subtraction_expression;

template<typename A, typename B>
using subtraction_expression =
  typename evaluate_subtraction_expression<subtraction_expression_impl_2<A, B>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct _is_negation_expression
{};
template<typename EXPRESSION>
constexpr bool is_negation_expression_v =
  std::is_base_of<_is_negation_expression, EXPRESSION>::value;

template<typename A>
struct negation_expression_impl_2
  : public unary_expression<A>
  , public _is_negation_expression
{
  using operand = A;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "negation(" << operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_negation_expression;

template<typename A>
using negation_expression =
  typename evaluate_negation_expression<negation_expression_impl_2<A>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct _is_affirmation_expression
{};
template<typename EXPRESSION>
constexpr bool is_affirmation_expression_v =
  std::is_base_of<_is_affirmation_expression, EXPRESSION>::value;

template<typename A>
struct affirmation_expression_impl_2
  : public unary_expression<A>
  , public _is_affirmation_expression
{
  using operand = A;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "affirmation(" << operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_affirmation_expression;

template<typename A>
using affirmation_expression =
  typename evaluate_affirmation_expression<affirmation_expression_impl_2<A>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct _is_exponentiation_expression
{};
template<typename EXPRESSION>
constexpr bool is_exponentiation_expression_v =
  std::is_base_of<_is_exponentiation_expression, EXPRESSION>;

template<typename A, typename B>
struct exponentiation_expression_impl_2
  : public binary_expression<A, B>
  , public _is_exponentiation_expression
{
  using left_operand = A;
  using right_operand = B;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "exponentiation(" << left_operand::to_string() << ", "
       << right_operand::to_string() << ")";
    return os.str();
  }
};

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_exponentiation_expression;

template<typename A, typename B>
using exponentiation_expression = typename evaluate_exponentiation_expression<
  exponentiation_expression_impl_2<A, B>>::type;

} // namespace primordialmachine