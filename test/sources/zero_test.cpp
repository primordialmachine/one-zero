///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's One Zero Library
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

TEST(one_zero_tests, zero_tests)
{
  using namespace primordialmachine;

  ASSERT_EQ(zero_functor<char>()(), zero<char>());
  ASSERT_EQ(0, zero_functor<char>()());

  ASSERT_EQ(zero_functor<signed char>()(), zero<signed char>());
  ASSERT_EQ(0, zero_functor<signed char>()());

  ASSERT_EQ(zero_functor<unsigned char>()(), zero<unsigned char>());
  ASSERT_EQ(0, zero_functor<unsigned char>()());

  ASSERT_EQ(zero_functor<signed short int>()(), zero<signed short int>());
  ASSERT_EQ(0, zero_functor<signed short int>()());

  ASSERT_EQ(zero_functor<unsigned short int>()(), zero<unsigned short int>());
  ASSERT_EQ(0, zero_functor<unsigned short int>()());

  ASSERT_EQ(zero_functor<signed long int>()(), zero<signed long int>());
  ASSERT_EQ(0, zero_functor<signed long int>()());

  ASSERT_EQ(zero_functor<unsigned long int>()(), zero<unsigned long int>());
  ASSERT_EQ(0, zero_functor<unsigned long int>()());

  ASSERT_EQ(zero_functor<signed long long int>()(),
            zero<signed long long int>());
  ASSERT_EQ(0, zero_functor<signed long long int>()());

  ASSERT_EQ(zero_functor<unsigned long long int>()(),
            zero<unsigned long long int>());
  ASSERT_EQ(0, zero_functor<unsigned long long int>()());

  ASSERT_EQ(zero_functor<int8_t>()(), zero<int8_t>());
  ASSERT_EQ(0, zero_functor<int8_t>()());

  ASSERT_EQ(zero_functor<int16_t>()(), zero<int16_t>());
  ASSERT_EQ(0, zero_functor<int16_t>()());

  ASSERT_EQ(zero_functor<int32_t>()(), zero<int32_t>());
  ASSERT_EQ(0, zero_functor<int32_t>()());

  ASSERT_EQ(zero_functor<int64_t>()(), zero<int64_t>());
  ASSERT_EQ(0, zero_functor<int64_t>()());

  ASSERT_EQ(zero_functor<uint8_t>()(), zero<uint8_t>());
  ASSERT_EQ(0, zero_functor<uint8_t>()());

  ASSERT_EQ(zero_functor<uint16_t>()(), zero<uint16_t>());
  ASSERT_EQ(0, zero_functor<uint16_t>()());

  ASSERT_EQ(zero_functor<uint32_t>()(), zero<uint32_t>());
  ASSERT_EQ(0, zero_functor<uint64_t>()());

  ASSERT_FLOAT_EQ(zero_functor<float>()(), zero<float>());
  ASSERT_FLOAT_EQ(0.F, zero_functor<float>()());

  ASSERT_DOUBLE_EQ(zero_functor<double>()(), zero<double>());
  ASSERT_DOUBLE_EQ(0., zero_functor<double>()());

  ASSERT_DOUBLE_EQ(zero_functor<long double>()(), zero<long double>());
  ASSERT_DOUBLE_EQ(0.L, zero_functor<long double>()());
}
