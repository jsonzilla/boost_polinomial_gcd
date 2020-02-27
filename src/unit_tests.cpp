#include "gtest/gtest.h"

#include <boost/math/tools/polynomial.hpp>

using namespace boost::math;
using namespace boost::math::tools; // for polynomial

TEST(poly, gdc_poly)
{
  polynomial<double> a{ {10, -6, -4, 3} };
  polynomial<double> b{ {-2.0, 1.0} };

  auto c = boost::math::tools::gcd(a, b);

  polynomial<double> d{ {6.0} };
  EXPECT_EQ(d, c);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}