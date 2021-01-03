#ifndef DTL_VECTOR_H_
#define DTL_VECTOR_H_

#include <initializer_list>
#include <iostream>
#include <string>


namespace dtl {

// Dynamic array-like contrainer of templates
template <typename _Tp>
class Vector {
 public:
  using value_type = _Tp;
  using pointer = _Tp*;
  using const_pointer = const _Tp*;
  using reference = _Tp&;
  using const_reference = const _Tp&;
  using difference_type = int;
  using size_type = int;

  static const size_type kDefaultCapacity = 5;

  Vector() : elements_(nullptr), capacity_(0), size_(0) {}

  Vector(size_type size)
      : capacity_(size > kDefaultCapacity ? size : kDefaultCapacity),
        size_(size) {
    elements_ = new _Tp[capacity_];
  }

  Vector(size_type size, const value_type& v) : Vector(size) {
    for (int i = 0; i < size_; i++) {
      elements_[i] = v;
    }
  }

  Vector(const std::initializer_list<value_type>& il) : Vector(il.size()) {
    size_type i = 0;
    for (auto v : il) {
      elements_[i++] = v;
    }
  }

  template <typename _Iter>
  Vector(_Iter& begin, _Iter& end);

  std::string ToString() {
    std::string str = "[";
    for (int i = 0; i < size_; i++) {
      str += std::to_string(elements_[i]);
      if (i < size_ - 1) str += ", ";
    }
    str += ']';
    return str;
  }

  size_type capacity() const noexcept { return capacity_; }

  size_type size() const noexcept { return size_; }

 private:
  pointer elements_;
  size_type capacity_;
  size_type size_;
};

}  // namespace dtl

#endif  // DTL_VECTOR_H_