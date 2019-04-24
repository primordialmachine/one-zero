///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's One Zero Functors Library
// Copyright (C) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "primordialmachine/one_zero_functors/include.hpp"
#include <gtest/gtest.h>

// clang-format off

#define VARIABLE_EXPRESSIONS_TESTS(VARIABLE_EXPRESSION, IS_VARIABLE_EXPRESSION, VARIABLE_NAME)\
{\
    using namespace primordialmachine;\
\
  /*subtract(v, v) -> zero*/\
  static_assert(is_zero_expression_v<subtraction_expression<VARIABLE_EXPRESSION, VARIABLE_EXPRESSION>>,\
                "failed: subtract(" VARIABLE_NAME ", " VARIABLE_NAME ") -> zero");\
\
  /*affirmate(v) -> v*/\
  static_assert(IS_VARIABLE_EXPRESSION<affirmation_expression<VARIABLE_EXPRESSION>>,\
                "failed: affirmate(" VARIABLE_NAME ") -> " VARIABLE_NAME);\
  /*negate(v) -> negate(v)*/\
  static_assert(is_negation_expression_v<negation_expression<VARIABLE_EXPRESSION>> &&\
                IS_VARIABLE_EXPRESSION<operand<negation_expression<VARIABLE_EXPRESSION>>>,\
                "failed: negate(" VARIABLE_NAME ") -> negate(" VARIABLE_NAME ")");\
\
  /*v + negation(v) -> zero*/\
  static_assert(is_zero_expression_v<addition_expression<VARIABLE_EXPRESSION, negation_expression<VARIABLE_EXPRESSION>>>,\
                "failed: " VARIABLE_NAME " + negate(" VARIABLE_NAME ") -> zero");\
  /*negation(v) + v -> zero*/\
  static_assert(is_zero_expression_v<addition_expression<negation_expression<VARIABLE_EXPRESSION>, VARIABLE_EXPRESSION>>,\
                "failed: negate(" VARIABLE_NAME ") + " VARIABLE_NAME " -> zero");\
\
  /*multiplication(one, v) -> v*/\
  static_assert(IS_VARIABLE_EXPRESSION<multiplication_expression<one_expression, VARIABLE_EXPRESSION>>,\
                "failed: multiply(one, " VARIABLE_NAME ") -> " VARIABLE_NAME);\
  /*multiplication(v, one) -> v*/\
  static_assert(IS_VARIABLE_EXPRESSION<multiplication_expression<VARIABLE_EXPRESSION, one_expression>>,\
                "failed: multiply(" VARIABLE_NAME ", one) -> " VARIABLE_NAME);\
\
  /*multiplication(zero, v) -> zero*/\
  static_assert(is_zero_expression_v<multiplication_expression<zero_expression, VARIABLE_EXPRESSION>>,\
                "failed: multiply(zero, " VARIABLE_NAME ") -> zero");\
  /*multiplication(v, zero) -> zero*/\
  static_assert(is_zero_expression_v<multiplication_expression<VARIABLE_EXPRESSION, zero_expression>>,\
                "failed: multiply(" VARIABLE_NAME ", zero) -> zero");\
\
  /*addition(zero, v) -> v*/\
  static_assert(IS_VARIABLE_EXPRESSION<addition_expression<zero_expression, VARIABLE_EXPRESSION>>,\
                "failed: add(zero, " VARIABLE_NAME ") -> " VARIABLE_NAME);\
  /*addition(v, zero) -> v*/\
  static_assert(IS_VARIABLE_EXPRESSION<addition_expression<VARIABLE_EXPRESSION, zero_expression>>,\
                "failed: add(" VARIABLE_NAME ", zero) -> " VARIABLE_NAME);\
\
  /*subtraction(v, zero) -> v*/\
  static_assert(IS_VARIABLE_EXPRESSION<subtraction_expression<VARIABLE_EXPRESSION, zero_expression>>,\
                "failed: " VARIABLE_NAME " - zero -> " VARIABLE_NAME);\
\
  /*addition(v, v) -> multiplication(v, 2)*/\
  static_assert(are_same_v<multiplication_expression<VARIABLE_EXPRESSION, integer_expression<2>>, addition_expression<VARIABLE_EXPRESSION, VARIABLE_EXPRESSION>>,\
                "failed: " VARIABLE_NAME " + " VARIABLE_NAME " -> " VARIABLE_NAME " * 2");\
}

// clang-format on