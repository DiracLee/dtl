// Run with:
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//   g++ vector_test.cc -o ../build/test -lgtest -lgtest_main -lpthread
//   ../build/test
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//

#include "../src/vector.h"

#include <vector>

#include "gtest/gtest.h"

constexpr static double eps = 1e-6;

class StlVectorTestSuite : public ::testing::Test {
 protected:
  ::std::vector<double> v0;
  ::std::vector<double> v1;
  ::std::vector<double> v2;
  ::std::vector<double> v3;
  ::std::vector<double> v4;
  ::std::vector<double> v5;
  ::std::vector<double> v6;
  ::std::vector<double> v7;
  ::std::vector<double> v8;
  ::std::vector<double> v9;
  ::std::vector<double> v10;

  StlVectorTestSuite()
      : v0(::std::vector<double>({2., 4., 6., 8., 10.})),
        v1(::std::vector<double>({1., 2., 3., 4., 5., 6.})),
        v2(::std::vector<double>({1., 2., 3., 4., 5.})),
        v3(::std::vector<double>(10)),
        v4(::std::vector<double>(4, 3.14)),
        v5(::std::vector<double>(v2.begin(), v2.end())),
        v6(::std::vector<double>(v2)),
        v7(::std::vector<double>(::std::move(v0))) {
    v8 = v2;
    v9 = {0., 2., 4., 6., 8.};
    v10 = ::std::move(v1);
  }
};

TEST_F(StlVectorTestSuite, ILConstructor) {
  ASSERT_EQ(v2.size(), 5);
  ASSERT_EQ(v2.capacity(), 5);
  double d = 1.;
  for (auto e : v2) {
    ASSERT_LE(e - d, eps);
    d += 1.;
  }
}

TEST_F(StlVectorTestSuite, SizeConstructor) {
  ASSERT_EQ(v3.size(), 10);
  ASSERT_EQ(v3.capacity(), 10);
  for (auto e : v3) {
    ASSERT_LE(e - 0., eps);
  }
}

TEST_F(StlVectorTestSuite, SizeValueConstructor) {
  ASSERT_EQ(v4.size(), 4);
  ASSERT_EQ(v4.capacity(), 4);
  double d = 3.14;
  for (auto e : v4) {
    ASSERT_LE(e - d, eps);
  }
}

TEST_F(StlVectorTestSuite, IteratorConstructor) {
  ASSERT_EQ(v5.size(), v2.size());
  ASSERT_EQ(v5.capacity(), v2.capacity());
  auto iter5 = v5.begin();
  auto iter2 = v2.begin();
  while (iter5 != v5.end()) {
    ASSERT_LE(*iter5 - *iter2, eps);
    ++iter5;
    ++iter2;
  }
}

TEST_F(StlVectorTestSuite, CopyConstructor) {
  ASSERT_EQ(v6.size(), v2.size());
  ASSERT_EQ(v6.capacity(), v2.capacity());
  auto iter6 = v6.begin();
  auto iter2 = v2.begin();
  while (iter6 != v6.end()) {
    ASSERT_LE(*iter6 - *iter2, eps);
    ++iter6;
    ++iter2;
  }
}

TEST_F(StlVectorTestSuite, MoveConstructor) {
  ASSERT_EQ(v0.data(), nullptr);
  ASSERT_EQ(v0.size(), 0);
  ASSERT_EQ(v0.capacity(), 0);
  ASSERT_EQ(v7.size(), 5);
  ASSERT_EQ(v7.capacity(), 5);
  double d = 2.;
  for (auto e : v7) {
    ASSERT_LE(e - d, eps);
    d += 2.;
  }
}

TEST_F(StlVectorTestSuite, CopyAssignment) {
  ASSERT_EQ(v8.size(), v2.size());
  ASSERT_EQ(v8.capacity(), v2.capacity());
  auto iter8 = v8.begin();
  auto iter2 = v8.begin();
  while (iter8 != v8.end()) {
    ASSERT_LE(*iter8 - *iter2, eps);
    ++iter8;
    ++iter2;
  }
}

TEST_F(StlVectorTestSuite, ILAssignment) {
  ASSERT_EQ(v9.size(), 5);
  ASSERT_EQ(v9.capacity(), 5);
  double d = 0.;
  for (auto e : v9) {
    ASSERT_LE(e - d, eps);
    d += 2.;
  }
}

TEST_F(StlVectorTestSuite, MoveAssignment) {
  ASSERT_EQ(v1.data(), nullptr);
  ASSERT_EQ(v1.size(), 0);
  ASSERT_EQ(v1.capacity(), 0);
  ASSERT_EQ(v10.size(), 6);
  ASSERT_EQ(v10.capacity(), 6);
  double d = 1.;
  for (auto e : v10) {
    ASSERT_LE(e - d, eps);
    d += 1.;
  }
}

//=========================================================================

class DtlVectorTestSuite : public ::testing::Test {
 protected:
  ::dtl::Vector<double> v0;
  ::dtl::Vector<double> v1;
  ::dtl::Vector<double> v2;
  ::dtl::Vector<double> v3;
  ::dtl::Vector<double> v4;
  ::dtl::Vector<double> v5;
  ::dtl::Vector<double> v6;
  ::dtl::Vector<double> v7;
  ::dtl::Vector<double> v8;
  ::dtl::Vector<double> v9;
  ::dtl::Vector<double> v10;

  DtlVectorTestSuite()
      : v0(::dtl::Vector<double>({2., 4., 6., 8., 10.})),
        v1(::dtl::Vector<double>({1., 2., 3., 4., 5., 6.})),
        v2(::dtl::Vector<double>({1., 2., 3., 4., 5.})),
        v3(::dtl::Vector<double>(10)),
        v4(::dtl::Vector<double>(4, 3.14)),
        v5(::dtl::Vector<double>(v2.begin(), v2.end())),
        v6(::dtl::Vector<double>(v2)),
        v7(::dtl::Vector<double>(::std::move(v0))){
    v8 = v2;
    v9 = {0., 2., 4., 6., 8.};
    v10 = ::std::move(v1);
  }
};

TEST_F(DtlVectorTestSuite, ILConstructor) {
  ASSERT_EQ(v2.size(), 5);
  ASSERT_EQ(v2.capacity(), 5);
  double d = 1.;
  for (auto e : v2) {
    ASSERT_LE(e - d, eps);
    d += 1.;
  }
}

TEST_F(DtlVectorTestSuite, SizeConstructor) {
  ASSERT_EQ(v3.size(), 10);
  ASSERT_EQ(v3.capacity(), 10);
  for (auto e : v3) {
    ASSERT_LE(e - 0., eps);
  }
}

TEST_F(DtlVectorTestSuite, SizeValueConstructor) {
  ASSERT_EQ(v4.size(), 4);
  ASSERT_EQ(v4.capacity(), 4);
  double d = 3.14;
  for (auto e : v4) {
    ASSERT_LE(e - d, eps);
  }
}

TEST_F(DtlVectorTestSuite, IteratorConstructor) {
  ASSERT_EQ(v5.size(), v2.size());
  ASSERT_EQ(v5.capacity(), v2.capacity());
  auto iter5 = v5.begin();
  auto iter2 = v2.begin();
  while (iter5 != v5.end()) {
    ASSERT_LE(*iter5 - *iter2, eps);
    ++iter5;
    ++iter2;
  }
}

TEST_F(DtlVectorTestSuite, CopyConstructor) {
  ASSERT_EQ(v6.size(), v2.size());
  ASSERT_EQ(v6.capacity(), v2.capacity());
  auto iter6 = v6.begin();
  auto iter2 = v2.begin();
  while (iter6 != v6.end()) {
    ASSERT_LE(*iter6 - *iter2, eps);
    ++iter6;
    ++iter2;
  }
}

TEST_F(DtlVectorTestSuite, MoveConstructor) {
  ASSERT_EQ(v0.data(), nullptr);
  ASSERT_EQ(v0.size(), 0);
  ASSERT_EQ(v0.capacity(), 0);
  ASSERT_EQ(v7.size(), 5);
  ASSERT_EQ(v7.capacity(), 5);
  double d = 2.;
  for (auto e : v7) {
    ASSERT_LE(e - d, eps);
    d += 2.;
  }
}

TEST_F(DtlVectorTestSuite, CopyAssignment) {
  ASSERT_EQ(v8.size(), v2.size());
  ASSERT_EQ(v8.capacity(), v2.capacity());
  auto iter8 = v8.begin();
  auto iter2 = v8.begin();
  while (iter8 != v8.end()) {
    ASSERT_LE(*iter8 - *iter2, eps);
    ++iter8;
    ++iter2;
  }
}

TEST_F(DtlVectorTestSuite, ILAssignment) {
  ASSERT_EQ(v9.size(), 5);
  ASSERT_EQ(v9.capacity(), 5);
  double d = 0.;
  for (auto e : v9) {
    ASSERT_LE(e - d, eps);
    d += 2.;
  }
}

TEST_F(DtlVectorTestSuite, MoveAssignment) {
  ASSERT_EQ(v1.data(), nullptr);
  ASSERT_EQ(v1.size(), 0);
  ASSERT_EQ(v1.capacity(), 0);
  ASSERT_EQ(v10.size(), 6);
  ASSERT_EQ(v10.capacity(), 6);
  double d = 1.;
  for (auto e : v10) {
    ASSERT_LE(e - d, eps);
    d += 1.;
  }
}
