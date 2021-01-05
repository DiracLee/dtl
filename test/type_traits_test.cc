// Run with:
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//   g++ type_traits_test.cc -o ../build/test -lgtest -lgtest_main -lpthread
//   ../build/test
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//

#include "../src/type_trait.h"
#include "gtest/gtest.h"

TEST(DtlTypeTraitsTest, IsSameType) {
  bool claim = ::dtl::is_same_type<int, int>::value;
  ASSERT_TRUE(claim);
}

TEST(DtlTypeTraitsTest, IsDifferentType) {
  bool claim = ::dtl::is_same_type<int, float>::value;
  ASSERT_FALSE(claim);
}
