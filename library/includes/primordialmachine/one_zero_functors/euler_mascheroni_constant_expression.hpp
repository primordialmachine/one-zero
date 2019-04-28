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

#include "primordialmachine/one_zero_functors/variable_expression.hpp"

namespace primordialmachine {

namespace tag {
struct euler_mascheroni_constant_expression
{};
} // namespace tag
template<typename A>
constexpr bool is_euler_mascheroni_constant_expression_v =
  has_tag<A, tag::euler_mascheroni_constant_expression>();

struct euler_mascheroni_constant_expression
  : public variable_expression
  , public tag::euler_mascheroni_constant_expression
{
  static std::string to_string() { return "[euler-mascheroni-constant]"; }
}; // struct euler_mascheroni_constant_expression

} // namespace primordialmachine
