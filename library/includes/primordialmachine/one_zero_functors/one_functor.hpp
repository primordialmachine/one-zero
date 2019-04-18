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

#include "primordialmachine/one_zero_functors/value_of_euler_mascheroni_constant_expression.hpp"
#include "primordialmachine/one_zero_functors/value_of_e_expression.hpp"
#include "primordialmachine/one_zero_functors/value_of_golden_ratio_expression.hpp"
#include "primordialmachine/one_zero_functors/value_of_one_expression.hpp"
#include "primordialmachine/one_zero_functors/value_of_pi_expression.hpp"
#include "primordialmachine/one_zero_functors/value_of_zero_expression.hpp"

namespace primordialmachine {

template<typename T>
struct one_functor
{
  using result_type = T;
  constexpr result_type operator()() const noexcept
  {
    return value_of_expression<T, one_expression>()();
  }
}; // struct one_functor

template<typename T>
struct pi_functor
{
  using result_type = T;
  constexpr result_type operator()() const noexcept
  {
    return value_of_expression<T, pi_expression>()();
  }
}; // struct pi_functor

template<typename T>
struct zero_functor
{
  using result_type = T;
  constexpr result_type operator()() const noexcept
  {
    return value_of_expression<T, zero_expression>()();
  }
}; // struct zero_functor

template<typename T>
struct e_functor
{
  using result_type = T;
  constexpr result_type operator()() const noexcept
  {
    return value_of_expression<T, e_expression>()();
  }
}; // struct e_functor

template<typename T>
struct golden_ratio_functor
{
  using result_type = T;
  constexpr result_type operator()() const noexcept
  {
    return value_of_expression<T, golden_ratio_expression>()();
  }
}; // struct golden_ratio_functor

template<typename T>
struct euler_mascheroni_constant_functor
{
  using result_type = T;
  constexpr result_type operator()() const noexcept
  {
    return value_of_expression<T, euler_mascheroni_constant_expression>()();
  }
}; // struct euler_mascheroni_constant_functor

} // namespace primordialmachine
