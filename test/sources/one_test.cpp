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

TEST(one_zero_tests, one_tests)
{
  using namespace primordialmachine;

  ASSERT_EQ(one_functor<char>()(), one<char>());
  ASSERT_EQ(1, one_functor<char>()());

  ASSERT_EQ(one_functor<signed char>()(), one<signed char>());
  ASSERT_EQ(1, one_functor<signed char>()());

  ASSERT_EQ(one_functor<unsigned char>()(), one<unsigned char>());
  ASSERT_EQ(1, one_functor<unsigned char>()());

  ASSERT_EQ(one_functor<signed short int>()(), one<signed short int>());
  ASSERT_EQ(1, one_functor<signed short int>()());

  ASSERT_EQ(one_functor<unsigned short int>()(), one<unsigned short int>());
  ASSERT_EQ(1, one_functor<unsigned short int>()());

  ASSERT_EQ(one_functor<unsigned long int>()(), one<unsigned long int>());
  ASSERT_EQ(1, one_functor<signed long int>()());

  ASSERT_EQ(one_functor<unsigned long int>()(), one<unsigned long int>());
  ASSERT_EQ(1, one_functor<unsigned long int>()());

  ASSERT_EQ(one_functor<signed long long int>()(), one<signed long long int>());
  ASSERT_EQ(1, one_functor<signed long long int>()());

  ASSERT_EQ(one_functor<unsigned long long int>()(),
            one<unsigned long long int>());
  ASSERT_EQ(1, one_functor<unsigned long long int>()());

  ASSERT_EQ(one_functor<int8_t>()(), one<int8_t>());
  ASSERT_EQ(1, one_functor<int8_t>()());

  ASSERT_EQ(one_functor<int16_t>()(), one<int16_t>());
  ASSERT_EQ(1, one_functor<int16_t>()());

  ASSERT_EQ(one_functor<int32_t>()(), one<int32_t>());
  ASSERT_EQ(1, one_functor<int32_t>()());

  ASSERT_EQ(one_functor<int64_t>()(), one<int64_t>());
  ASSERT_EQ(1, one_functor<int64_t>()());

  ASSERT_EQ(one_functor<uint8_t>()(), one<uint8_t>());
  ASSERT_EQ(1, one_functor<uint8_t>()());

  ASSERT_EQ(one_functor<uint16_t>()(), one<uint16_t>());
  ASSERT_EQ(1, one_functor<uint16_t>()());

  ASSERT_EQ(one_functor<uint32_t>()(), one<uint32_t>());
  ASSERT_EQ(1, one_functor<uint32_t>()());

  ASSERT_EQ(one_functor<uint64_t>()(), one<uint64_t>());
  ASSERT_EQ(1, one_functor<uint64_t>()());

  ASSERT_FLOAT_EQ(one_functor<float>()(), one<float>());
  ASSERT_FLOAT_EQ(1.F, one_functor<float>()());

  ASSERT_DOUBLE_EQ(one_functor<double>()(), one<double>());
  ASSERT_DOUBLE_EQ(1., one_functor<double>()());

  ASSERT_DOUBLE_EQ(one_functor<long double>()(), one<long double>());
  ASSERT_DOUBLE_EQ(1.L, one_functor<long double>()());
}
