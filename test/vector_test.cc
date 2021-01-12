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

  // ASSERT_EQ(v2.capacity(), v1.capacity());

  // ::std::iterator_traits<decltype(v2.begin())>::iterator_category;
  // ::std::iterator_traits<decltype(v2.begin())>::difference_type;
  // ::std::iterator_traits<decltype(v2.begin())>::value_type;
  // ::std::iterator_traits<decltype(v2.begin())>::reference;
  // ::std::iterator_traits<decltype(v2.begin())>::pointer;

  using TYPE = int;
  {
    using TYPE = float;
    TYPE b = 5.2;
    ASSERT_LE(b - 5.2, 0.001);
  }

  TYPE a = 5.2;
  ASSERT_EQ(a, 5);
}

class DtlVectorTestSuite : public ::testing::Test {
 protected:
  ::std::vector<double> v0{2., 4., 6., 8., 10.};

  ::dtl::Vector<double> v1;
  ::dtl::Vector<double> v2{1., 2., 3., 4., 5.};
  ::dtl::Vector<double> v3{4};
  ::dtl::Vector<double> v4{4, 3.14};
  ::dtl::Vector<double> v5{v0.begin(), v0.end()};
  ::dtl::Vector<double> v6{v3};
  ::dtl::Vector<double> v7{::std::move(v3)};
};

TEST_F(DtlVectorTestSuite, DefaultConstructor) { ::dtl::Vector<double> v; }

TEST_F(DtlVectorTestSuite, ILConstructor) {
  ::dtl::Vector<double> v{1., 2., 3., 4., 5.};
}

TEST_F(DtlVectorTestSuite, SizeConstructor) { ::dtl::Vector<double> v{4}; }

TEST_F(DtlVectorTestSuite, SizeValueConstructor) {
  ::dtl::Vector<double> v3{4, 3.14};
}

TEST_F(DtlVectorTestSuite, IteratorConstructor) {
  ::dtl::Vector<double> v{v0.begin(), v0.end()};
}

TEST_F(DtlVectorTestSuite, CopyConstructor) { ::dtl::Vector<double> v{v3}; }

TEST_F(DtlVectorTestSuite, MoveConstructor) {
  ::dtl::Vector<double> v{::std::move(v3)};
}