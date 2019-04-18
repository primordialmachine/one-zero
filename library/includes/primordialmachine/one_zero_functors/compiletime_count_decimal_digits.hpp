#pragma once

namespace primordialmachine::compiletime {

/**@{*/

/**
 * @brief Get the number of decimal digits in an <tt>unsigned long long</tt>
 * value <em>at compile-time</em>.
 * @param x The unsigned int.
 * @return The number of decimal digits in the value @a x.
 */
constexpr size_t
count_decimal_digits(unsigned long long int x) noexcept
{
  constexpr const unsigned long long int BASE = 10ULL;
  return (x < BASE)
           ? 1
           : 1 + count_decimal_digits((unsigned long long int)(x / BASE));
}

/**@}*/

static_assert(count_decimal_digits(0) == 1, "sanity check failed");
static_assert(count_decimal_digits(1) == 1, "sanity check failed");
static_assert(count_decimal_digits(2) == 1, "sanity check failed");
static_assert(count_decimal_digits(3) == 1, "sanity check failed");
static_assert(count_decimal_digits(4) == 1, "sanity check failed");
static_assert(count_decimal_digits(5) == 1, "sanity check failed");
static_assert(count_decimal_digits(6) == 1, "sanity check failed");
static_assert(count_decimal_digits(7) == 1, "sanity check failed");
static_assert(count_decimal_digits(8) == 1, "sanity check failed");
static_assert(count_decimal_digits(9) == 1, "sanity check failed");

static_assert(count_decimal_digits(10) == 2, "sanity check failed");
static_assert(count_decimal_digits(11) == 2, "sanity check failed");
static_assert(count_decimal_digits(12) == 2, "sanity check failed");
static_assert(count_decimal_digits(13) == 2, "sanity check failed");
static_assert(count_decimal_digits(14) == 2, "sanity check failed");
static_assert(count_decimal_digits(15) == 2, "sanity check failed");
static_assert(count_decimal_digits(16) == 2, "sanity check failed");
static_assert(count_decimal_digits(17) == 2, "sanity check failed");
static_assert(count_decimal_digits(18) == 2, "sanity check failed");
static_assert(count_decimal_digits(19) == 2, "sanity check failed");
static_assert(count_decimal_digits(20) == 2, "sanity check failed");

} // namespace primordialmachine::compiletime
