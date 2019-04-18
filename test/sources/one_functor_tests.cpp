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

// Performs the following tests:
// c == f
// where c is a literal representing one of type T and f is the one functor of
// type T.
TEST(one_zero_functor_tests, one_functor_test)
{
  using namespace primordialmachine;

  ASSERT_EQ(1, one_functor<char>()());
  ASSERT_EQ(1, one_functor<signed char>()());
  ASSERT_EQ(1, one_functor<unsigned char>()());

  ASSERT_EQ(1, one_functor<signed short int>()());
  ASSERT_EQ(1, one_functor<unsigned short int>()());

  ASSERT_EQ(1L, one_functor<signed long int>()());
  ASSERT_EQ(1UL, one_functor<unsigned long int>()());

  ASSERT_EQ(1LL, one_functor<signed long long int>()());
  ASSERT_EQ(1ULL, one_functor<unsigned long long int>()());

  ASSERT_EQ(UINT8_C(1), one_functor<int8_t>()());
  ASSERT_EQ(UINT8_C(1), one_functor<uint8_t>()());

  ASSERT_EQ(INT16_C(1), one_functor<int16_t>()());
  ASSERT_EQ(UINT16_C(1), one_functor<uint16_t>()());

  ASSERT_EQ(INT32_C(1), one_functor<int32_t>()());
  ASSERT_EQ(UINT32_C(1), one_functor<uint32_t>()());

  ASSERT_EQ(INT64_C(1), one_functor<int64_t>()());
  ASSERT_EQ(UINT64_C(1), one_functor<uint64_t>()());

  ASSERT_FLOAT_EQ(1.F, one_functor<float>()());
  ASSERT_DOUBLE_EQ(1., one_functor<double>()());
  ASSERT_DOUBLE_EQ(1.L, one_functor<long double>()());
}
