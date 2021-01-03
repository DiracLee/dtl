#include "../src/vector.h"

#include <iostream>
#include <vector>

#include "gtest/gtest.h"

int main() {
  dtl::Vector<int> v1;
  std::cout << v1.ToString() << std::endl;

  dtl::Vector<int> v2(10);
  std::cout << v2.ToString() << std::endl;

  dtl::Vector<int> v3(10, 3);
  std::cout << v3.ToString() << std::endl;

  dtl::Vector<int> v4{1, 3, 5, 7, 9};
  std::cout << v4.ToString() << std::endl;

  return 0;
}