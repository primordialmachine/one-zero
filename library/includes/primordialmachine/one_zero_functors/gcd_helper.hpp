///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Constants Library
// Copyright (c) 2017-2019 Michael Heilmann
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
#include <type_traits>

namespace primordialmachine {

/// Functor computing the greatest common divisor (gcd) for two integers
/// which must be non-negative and at least one of them must be non-zero.
/// If a gcd exists, then it is non-negative and is returned. Otherwise
/// 0 is returned.
/// The algortithm can be described as follows.
/// gcd(a, 0) = a (non-zero as a must be non-zero)
/// gcd(0, b) = b (non-zero as b must be non-zero)
/// gcd(1, b) = gcd(a, 1) = 1
/// gcd(a, b) = a (or equivalently gcd(a,b) = b)  if a = b
/// gcd(a, b) = gcd(a - b, b)                     if a > b
/// gcd(a, b) = gcd(a, b - a)                     if b > a
/// A positive return value indicates success and is the GCD of the arguments a
/// and b. A return value of 0 indicates failure.

namespace internal {
template<int A, int B, typename E = void>
struct gcd_implementation;

template<int A, int B>
struct gcd_implementation<A,
                          B,
                          enable_if<((A >= 0 && B >= 0) && (A != 0 || B != 0))>>
{
  constexpr int operator()() const noexcept { return implementation(); }

  constexpr int implementation() const noexcept
  {
    // Case of gcd(a, 0) = a.
    if constexpr (B == 0) {
      return A;
    }
    // Case of gcd(0, b) = b.
    if constexpr (A == 0) {
      return B;
    }

    // Neither a nor b are zero now.

    // Case of gcd(1, b) or gcd(a, 1)
    if constexpr (A == 1 || B == 1) {
      return 1;
    }
    // Case of gcd(a,b) (or equivalently gcd(a,b)) if a = b.
    if constexpr (A == B) {
      return A;
    }
    // Case of gcd(a, b) = gcd(a - b, b) if a > b.
    if constexpr (A > B) {
      return gcd_implementation<A - B, B>()();
    }
    // Case of gcd(a,b) = gcd(a, b - a) if a < b.
    else /*if (a < b) */
    {
      return gcd_implementation<A, B - A>()();
    }
  }
};
}

template<int a, int b>
constexpr int
gcd() noexcept
{
  return internal::gcd_implementation<a, b>()();
}

} // namespace primordialmachine
