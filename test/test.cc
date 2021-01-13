#include <iostream>
#include <vector>

#include "../src/vector.h"

int main() {
  ::dtl::Vector<double> v0;
  ::dtl::Vector<double> v7;
  v0 = ::dtl::Vector<double>({2., 4., 6., 8., 10.});
  ::std::cout << v0.end() - v0.begin() << "\n";
  v7 = ::dtl::Vector<double>(::std::move(v0));
  ::std::cout << v7.size() << "\n";

  return 0;
}

// 2 x
// 3 x
// 4 x
// 5
// 6
// 7 x


// C++ 编译 & 链接

// g++ -c test.cc -o test.o  # 编译：语法检查
// => test.o
// nm -C test.o
// => 查看函数定义的相对地址（有可能缺失，在链接阶段确定）
// g++ test.o   # 链接：查找函数定义

// g++ -c add.cc -o add.o
// => add.o
// nm -C add.o
// g++ test.o add.o

// 链接阶段两种出错
// - 未找到定义
// - 定义冗余

// .cc 用于实现  .cpp 用于 main/test