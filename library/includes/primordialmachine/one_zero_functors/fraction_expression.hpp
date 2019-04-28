#pragma once

#include "primordialmachine/one_zero_functors/gcd_helper.hpp"
#include "primordialmachine/one_zero_functors/integer_expression.hpp"
#include "primordialmachine/one_zero_functors/one_expression.hpp"
#include "primordialmachine/one_zero_functors/zero_expression.hpp"

namespace primordialmachine {

struct fraction_expression_tag
{};

// Test if a type is an expression type.
template<typename A>
constexpr bool is_fraction_expression_v = has_tag<A, fraction_expression_tag>();

template<typename EXPRESSION, typename ENABLED = void>
struct evaluate_fraction_expression;

template<typename EXPRESSION>
using nominator = typename EXPRESSION::nominator;

template<typename EXPRESSION>
using denominator = typename EXPRESSION::denominator;

template<typename NOMINATOR, typename DENOMINATOR>
struct fraction_expression_implementation
  : public expression
  , public fraction_expression_tag
{
  using nominator = NOMINATOR;
  using denominator = DENOMINATOR;
  static std::string to_string()
  {
    std::ostringstream os;
    os << "fraction(" << nominator::to_string() << ", "
       << denominator::to_string() << ")";
    return os.str();
  }
}; // struct fraction_expression_implementation

template<typename NOMINATOR, typename DENOMINATOR>
using fraction_expression = typename evaluate_fraction_expression<
  fraction_expression_implementation<NOMINATOR, DENOMINATOR>>::type;

template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<!are_same_v<nominator<EXPRESSION>, denominator<EXPRESSION>> &&
            !has_tag<nominator<EXPRESSION>, integer_expression_tag>() &&
            !has_any_tag<denominator<EXPRESSION>,
                         integer_expression_tag,
                         zero_expression_tag,
                         one_expression_tag>()>>
{
  using type =
    fraction_expression<nominator<EXPRESSION>, denominator<EXPRESSION>>;
};

template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<is_zero_expression_v<denominator<EXPRESSION>>>>
{
  using type = error_expression;
};

// A / B = 1 if A = B and A, B != 0
template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<are_same_v<nominator<EXPRESSION>, denominator<EXPRESSION>> &&
            (!is_zero_expression_v<nominator<EXPRESSION>>)&&(
              !is_zero_expression_v<denominator<EXPRESSION>>)>>
{
  using type = one_expression;
};

template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<!are_same_v<nominator<EXPRESSION>, denominator<EXPRESSION>> &&
            is_one_expression_v<denominator<EXPRESSION>>>>
{
  using type = nominator<EXPRESSION>;
};

template<typename EXPRESSION>
struct evaluate_multiplication_expression<
  EXPRESSION,
  enable_if<is_fraction_expression_v<left_operand<EXPRESSION>> &&
            is_fraction_expression_v<right_operand<EXPRESSION>>>>
{
  using left_operand = left_operand<EXPRESSION>;
  using right_operand = right_operand<EXPRESSION>;
  using type =
    fraction_expression<multiplication_expression<nominator<left_operand>,
                                                  nominator<right_operand>>,
                        multiplication_expression<denominator<left_operand>,
                                                  denominator<right_operand>>>;
};

// This is the case where nominator and denominator are positive and are not
// equal.
template<typename EXPRESSION>
struct evaluate_fraction_expression<
  EXPRESSION,
  enable_if<is_integer_expression_v<nominator<EXPRESSION>> &&
            is_integer_expression_v<denominator<EXPRESSION>> &&
            (nominator<EXPRESSION>::value != denominator<EXPRESSION>::value) &&
            (nominator<EXPRESSION>::value > 0) &&
            (denominator<EXPRESSION>::value > 0)>>
{
  // As N and D are both positive, there exists a GCD.
  static constexpr const int gcd =
    gcd<nominator<EXPRESSION>::value, denominator<EXPRESSION>::value>();

  // The case of N = D is checked afterwards.
  using type = fraction_expression<
    integer_expression<(nominator<EXPRESSION>::value / gcd)>,
    integer_expression<(denominator<EXPRESSION>::value / gcd)>>;
};

} // namespace primordialmachine
