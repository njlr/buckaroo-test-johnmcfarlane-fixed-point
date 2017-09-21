#include <type_traits>
#include <sg14/fixed_point>
#include <gtest/gtest.h>

TEST(fixedpoint, basicarithmetic) {

  using namespace sg14;

  // define a constant signed value with 3 integer and 28 fractional bits (s3:28)
  auto pi = fixed_point<int32_t, -28>{ 3.1415926535 };

  // expressions involving integers return fixed_point results
  auto tau = pi * 2;
  static_assert(std::is_same<decltype(tau), fixed_point<int32_t, -28>>::value, "");

  // EXPECT_TRUE(6.28319 == tau);

  // expressions involving floating-point values return floating-point results
  auto degrees = tau * (180 / 3.1415926534);
  static_assert(std::is_same<decltype(degrees), double>::value, "");

  // EXPECT_EQ(360.0, degrees);
}
