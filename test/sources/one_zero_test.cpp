#include "primordialmachine/one_zero_functors/include.hpp"
#include <gtest/gtest.h>

TEST(one_test, one_test)
{
  using namespace primordialmachine;
  ASSERT_EQ(1, one_functor<signed char>::value);
  ASSERT_EQ(1, one_functor<unsigned char>::value);
  ASSERT_EQ(1, one_functor<signed short int>::value);
  ASSERT_EQ(1, one_functor<unsigned short int>::value);
  ASSERT_EQ(1, one_functor<signed long int>::value);
  ASSERT_EQ(1, one_functor<unsigned long int>::value);
  ASSERT_EQ(1, one_functor<signed long long int>::value);
  ASSERT_EQ(1, one_functor<unsigned long long int>::value);
  ASSERT_FLOAT_EQ(1.F, one_functor<float>::value);
  ASSERT_DOUBLE_EQ(1.L, one_functor<double>::value);
  // @todo Google Test is missing ASSERT_LONG_DOUBLE_EQ?
}

TEST(zero_test, zero_test)
{
  using namespace primordialmachine;
  ASSERT_EQ(0, zero_functor<signed char>::value);
  ASSERT_EQ(0, zero_functor<unsigned char>::value);
  ASSERT_EQ(0, zero_functor<signed short int>::value);
  ASSERT_EQ(0, zero_functor<unsigned short int>::value);
  ASSERT_EQ(0, zero_functor<signed long int>::value);
  ASSERT_EQ(0, zero_functor<unsigned long int>::value);
  ASSERT_EQ(0, zero_functor<signed long long int>::value);
  ASSERT_EQ(0, zero_functor<unsigned long long int>::value);
  ASSERT_FLOAT_EQ(0.F, zero_functor<float>::value);
  ASSERT_DOUBLE_EQ(0.L, zero_functor<double>::value);
  // @todo Google Test is missing ASSERT_LONG_DOUBLE_EQ?
}
