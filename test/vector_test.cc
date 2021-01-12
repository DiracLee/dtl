// Run with:
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//   g++ vector_test.cc -o ../build/test -lgtest -lgtest_main -lpthread
//   ../build/test
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//

#include "../src/vector.h"

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
  // ASSERT_EQ(v2.size(), 0);

  int *p = new int[3]{10};

  // ASSERT_EQ(sizeof(p), 8);

  ::std::vector<double> v11(5);
  auto iter11 = v11.begin();
  auto iter2 = v2.begin();
  while (iter11 != v11.end()) *iter11++ = *iter2++;
  for (int i = 0; i < v2.size(); i++) {
    ASSERT_EQ(v2[i], v11[i]);
  }

  v2.rend();

  v2.reserve(10);
  v1 = v2;

  ASSERT_EQ(v2.capacity(), v1.capacity());


  ::std::iterator_traits<decltype(v2.begin())>::iterator_category;
  ::std::iterator_traits<decltype(v2.begin())>::difference_type;
  ::std::iterator_traits<decltype(v2.begin())>::value_type;
  ::std::iterator_traits<decltype(v2.begin())>::reference;
  ::std::iterator_traits<decltype(v2.begin())>::pointer;
}

// class DtlVectorTestSuite : public ::testing::Test {
//  protected:
//   ::dtl::Vector<int> v;
// };