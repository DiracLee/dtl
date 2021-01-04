#ifndef DTL_ARRAY_H_
#define DTL_ARRAY_H_

#include <iterator>

namespace dtl {

template <typename _Tp, size_t _Nm>
struct Array {
  using value_type = _Tp;
  using pointer = _Tp *;
  using const_pointer = const _Tp *;
  using reference = _Tp &;
  using const_reference = const _Tp &;
  using size_type = size_t;
  using iterator = _Tp *;

  value_type instance_[_Nm ? _Nm : 1];

  iterator begin();

  iterator end();
};

}  // namespace dtl

#endif  // DTL_ARRAY_H_