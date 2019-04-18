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

#pragma once

#include "primordialmachine/one_zero_functors/expression.hpp"
#include "primordialmachine/one_zero_functors/fraction_expression.hpp"

namespace primordialmachine {

// f(e0, e1) -> f(e1, e0)
// f in (ADD U MULTIPLY U FRACTION)
// e0, e1 in EXPRESSION
template<typename EXPRESSION, typename ENABLED = void>
struct swap_implementation;

template<typename EXPRESSION>
struct swap_implementation<EXPRESSION,
                           enable_if<(is_add_expression_v<EXPRESSION> ||
                                      is_multiply_expression_v<EXPRESSION> ||
                                      is_fraction_expression_v<EXPRESSION>)>>
{
  using type =
    add_expression<right_operand<EXPRESSION>, left_operand<EXPRESSION>>;
}; // struct swap_implementation

template<typename EXPRESSION>
using swap = typename swap_implementation<EXPRESSION>::type;

} // namespace primordialmachine
