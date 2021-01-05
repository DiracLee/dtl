#include <iostream>

int main()
{
  double *p = new double[10]{2.5};
  for (int i = 0; i < 10; i ++) std::cout << p[i] << " ";  // 2.5 0 0 0 0 0 0 0 0 0
  puts("");
  delete[] p;
  return 0; 
}