///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's One Zero Library
// Copyright (C) 2017-2018 Michael Heilmann
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

namespace primordialmachine {

template<typename TYPE>
struct zero_functor;

template<>
struct zero_functor<signed char>
{
  static constexpr signed char value = 0;
}; // struct zero_functor
template<>
struct zero_functor<unsigned char>
{
  static constexpr unsigned char value = 0;
}; // struct zero_functor

template<>
struct zero_functor<signed short int>
{
  static constexpr signed short int value = 0;
}; // struct zero_functor
template<>
struct zero_functor<unsigned short int>
{
  static constexpr unsigned short int value = 0;
}; // struct zero_functor

template<>
struct zero_functor<signed int>
{
  static constexpr signed int value = 0;
}; // struct zero_functor
template<>
struct zero_functor<unsigned int>
{
  static constexpr unsigned int value = 0;
}; // struct zero_functor

template<>
struct zero_functor<signed long int>
{
  static constexpr signed long int value = 0L;
}; // struct zero_functor
template<>
struct zero_functor<unsigned long int>
{
  static constexpr unsigned long int value = 0UL;
}; // struct zero_functor

template<>
struct zero_functor<signed long long int>
{
  static constexpr signed long long int value = 0LL;
}; // struct zero_functor
template<>
struct zero_functor<unsigned long long int>
{
  static constexpr unsigned long long int value = 0ULL;
}; // struct zero_functor

template<>
struct zero_functor<float>
{
  static constexpr float value = 0.F;
}; // struct zero_functor
template<>
struct zero_functor<double>
{
  static constexpr double value = 0.;
}; // struct zero_functor
template<>
struct zero_functor<long double>
{
  static constexpr long double value = 0.L;
}; // struct zero_functor

} // namespace primordialmachine
