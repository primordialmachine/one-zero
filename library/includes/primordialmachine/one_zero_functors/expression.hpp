#pragma once

#include <sstream>
#include <type_traits>

namespace primordialmachine {

template<typename EXPRESSION, typename ENABLED = void>
struct to_string;

} // namespace primordialmachine

namespace primordialmachine {

template<bool C, typename T = void>
using enable_if = std::enable_if_t<C, T>;

template<typename B, typename T>
constexpr bool is_base_of_v = std::is_base_of_v<B, T>;

template<typename A, typename B>
constexpr bool is_same_v = std::is_same_v<A, B>;

} // namespace primordialmachine

namespace primordialmachine {

template<typename EXPRESSION, typename TAG>
constexpr bool
has_tag() noexcept
{
  return is_base_of_v<TAG, EXPRESSION>;
}

template<typename EXPRESSION, typename... TAGS>
constexpr bool
has_any_tag() noexcept
{
  return (...|| has_tag<EXPRESSION, TAGS>());
}

} // namespace primordialmachine

namespace primordialmachine {

// Test if the types of two expressions are the same.
template<typename A, typename B>
constexpr bool are_same_v = is_same_v<A, B>;

struct expression_tag
{};

struct expression : public expression_tag
{}; // struct expression
// Test if a type is an expression type.
template<typename T>
constexpr bool is_expression_v = has_tag<T, expression_tag>();

} // namespace primordialmachine

namespace primordialmachine {

struct error_expression_tag
{};
template<typename T>
static constexpr bool is_error_expression_v =
  has_tag<T, error_expression_tag>();

struct error_expression
  : public expression
  , public error_expression_tag
{}; // struct error_expression

} // namespace primordialmachine

namespace primordialmachine {

template<typename EXPRESSION>
using left_operand = typename EXPRESSION::left_operand;

template<typename EXPRESSION>
using right_operand = typename EXPRESSION::right_operand;

template<typename EXPRESSION>
using operand = typename EXPRESSION::operand;

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
struct binary_expression : public expression
{
  using left_operand = LEFT_OPERAND;  // access via EXPRESSION::left_operand
  using right_operand = RIGHT_OPERAND; // access via EXPRESSION::right_operand
};

template<typename OPERAND>
struct unary_expression : public expression
{
  using operand = OPERAND; // access via EXPRESSION::operand
};

} // namespace primordialmachine

namespace primordialmachine {

struct addition_expression_tag
{};
template<typename A>
constexpr bool is_addition_expression_v = has_tag<A, addition_expression_tag>();

namespace internal {

template<typename A, typename B>
struct addition_expression_implementation
  : public binary_expression<A, B>
  , public addition_expression_tag
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

} // namespace internal

template<typename A, typename ENABLED = void>
struct evaluate_addition_expression;

template<typename A, typename B>
using addition_expression = typename evaluate_addition_expression<
  internal::addition_expression_implementation<A, B>>::type;
}

namespace primordialmachine {

struct multiplication_expression_tag
{};
template<typename A>
constexpr bool is_multiplication_expression_v =
  has_tag<A, multiplication_expression_tag>();

namespace internal {

template<typename A, typename B>
struct multiplication_expression_implementation
  : public binary_expression<A, B>
  , public multiplication_expression_tag
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

} // namespace internal

template<typename A, typename ENABLED = void>
struct evaluate_multiplication_expression;

template<typename A, typename B>
using multiplication_expression = typename evaluate_multiplication_expression<
  internal::multiplication_expression_implementation<A, B>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct subtraction_expression_tag
{};
template<typename A>
constexpr bool is_subtraction_expression_v =
  has_tag<A, subtraction_expression_tag>();

namespace internal {

template<typename A, typename B>
struct subtraction_expression_implementation
  : public binary_expression<A, B>
  , public subtraction_expression_tag
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

} // namespace internal

template<typename A, typename ENABLED = void>
struct evaluate_subtraction_expression;

template<typename A, typename B>
using subtraction_expression = typename evaluate_subtraction_expression<
  internal::subtraction_expression_implementation<A, B>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct negation_expression_tag
{};
template<typename A>
constexpr bool is_negation_expression_v = has_tag<A, negation_expression_tag>();

namespace internal {

template<typename A>
struct negation_expression_implementation
  : public unary_expression<A>
  , public negation_expression_tag
{
  using operand = typename unary_expression<A>::operand;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "negation(" << operand::to_string() << ")";
    return os.str();
  }
}; // struct negation_expression_implementation

} // namespace internal

template<typename A, typename ENABLED = void>
struct evaluate_negation_expression;

template<typename A>
using negation_expression = typename evaluate_negation_expression<
  internal::negation_expression_implementation<A>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct affirmation_expression_tag
{};
template<typename A>
constexpr bool is_affirmation_expression_v =
  has_tag<A, affirmation_expression_tag>();

namespace internal {

template<typename A>
struct affirmation_expression_implementation
  : public unary_expression<A>
  , public affirmation_expression_tag
{
  using operand = typename unary_expression<A>::operand;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "affirmation(" << operand::to_string() << ")";
    return os.str();
  }
}; // struct affirmation_expression_implementation

} // namespace internal

template<typename A, typename ENABLED = void>
struct evaluate_affirmation_expression;

template<typename A>
using affirmation_expression = typename evaluate_affirmation_expression<
  internal::affirmation_expression_implementation<A>>::type;

} // namespace primordialmachine

namespace primordialmachine {

struct exponentiation_expression_tag
{};
template<typename A>
constexpr bool is_exponentiation_expression_v =
  has_tag<A, exponentiation_expression_tag>();

template<typename EXPRESSION>
using base = left_operand<EXPRESSION>;

template<typename EXPRESSION>
using exponent = right_operand<EXPRESSION>;

namespace internal {

template<typename A, typename B>
struct exponentiation_expression_implementation
  : public binary_expression<A, B>
  , public exponentiation_expression_tag
{
  using base = typename binary_expression<A, B>::left_operand;
  using exponent = typename binary_expression<A, B>::right_operand;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "exponentiation(" << base::to_string() << ", "
       << exponent::to_string() << ")";
    return os.str();
  }
}; // struct exponentiation_expression_implementation

} // namespace internal

template<typename A, typename ENABLED = void>
struct evaluate_exponentiation_expression;

template<typename A, typename B>
using exponentiation_expression = typename evaluate_exponentiation_expression<
  internal::exponentiation_expression_implementation<A, B>>::type;

} // namespace primordialmachine
