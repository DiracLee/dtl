// Run with:
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//      g++ vector_test.cc -o ../build/vector_test -lgtest -lgtest_main
//      -lpthread
//      ../build/vector_test
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
#include "../src/vector.h"

#include <iostream>

#include "gtest/gtest.h"

class StlVectorTestSuite : public ::testing::Test {
 protected:
  ::std::vector<double> v1{};
  ::std::vector<double> v2{1., 2., 3., 4., 5.};
  ::std::vector<double> v3{4, 3.14};
  ::std::vector<double> v4{v2.begin(), v2.end()};
  ::std::vector<double> v5{v3};
  ::std::vector<double> v6{::std::allocator<double>()};
  ::std::vector<double> v7{::std::move(v3)};
  ::std::vector<double> v8{4, ::std::allocator<double>()};
  ::std::vector<double> v9{::std::move(v4), ::std::allocator<double>()};
  ::std::vector<double> v10{v2, ::std::allocator<double>()};
};

TEST_F(StlVectorTestSuite, AllFunc) {
  ::std::reverse_iterator<::std::vector<float>::iterator> rit;

  v2.reserve(10);
  ASSERT_EQ(v2.size(), 0);

}

// class DtlVectorTestSuite : public ::testing::Test {
//  protected:
//   ::dtl::Vector<int> v;
// };