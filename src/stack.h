#ifndef DTL_STACK_H_
#define DTL_STACK_H_

#include <iterator>

namespace dtl {

#include "deque.h"

// Stack / List / Deque
template <typename _Tp, typename _Sqc = dtl::Deque<_Tp>>
class Stack {
 public:
  using container = _Sqc;

  using value_type = typename container::value_type;
  using size_type = typename container::size_type;
  using reference = typename container::reference;
  using const_reference = typename container::const_reference;

  bool empty() const { return c.empty(); }
  size_type size() const { return c.size(); }
  reference front() { return c.front(); }
  const_reference front() const { return c.front(); }
  reference back() { return c.back(); }
  const_reference back() const { return c.back(); }

  void push(const value_type &x) { c.push_back(x); }

  void pop() { c.pop_back(); }

 private:
  container c;
};

}  // namespace dtl

#endif  // DTL_STACK_H_