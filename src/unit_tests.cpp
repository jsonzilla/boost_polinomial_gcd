#include "gtest/gtest.h"

#include "poly.h";

#include <vector>

TEST(example, demo)
{
  std::vector<double> a= { 2, 1, 1 };
  std::vector<double> b= { 1, 2, 2, 3 };
  std::vector<double> c = { 1, 3 };
  auto v = Poly::Division(b, a);

  EXPECT_EQ(v, c);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}