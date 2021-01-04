#ifndef DTL_DEQUE_H_
#define DTL_DEQUE_H_

#include <iterator>

namespace dtl {

template <typename _Tp, size_t _BufSz = 0>
struct DequeIterator {
  using iterator_category = std::random_access_iterator_tag;
  using value_type = _Tp;
  using pointer = _Tp *;
  using reference = _Tp &;
  using difference_type = ptrdiff_t;

  using size_type = size_t;
  using map_pointer = pointer *;
  using self = DequeIterator<_Tp, _BufSz>;

  static constexpr size_t kDequeBufSize = 512;

  inline size_t buf_size() {
    return _BufSz != 0 ? _BufSz
                       : (sizeof(_Tp) < kDequeBufSize
                              ? static_cast<size_t>(kDequeBufSize / sizeof(_Tp))
                              : static_cast<size_t>(1));
  }

  difference_type operator-(const self &rhs) const {
    return static_cast<difference_type>(buf_size()) *
               static_cast<difference_type>(node - rhs.node - 1) +
           static_cast<difference_type>(cur - first) +
           static_cast<difference_type>(rhs.last, rhs.cur);
  }

  bool operator==(const self &rhs);

  reference operator[](difference_type n);

  reference operator*() const { return *cur; }

  pointer operator->() const { return &(operator*()); }

  void set_node(map_pointer new_node) {
    node = new_node;
    first = *new_node;
    last = first + static_cast<difference_type>(buf_size());
  }

  self &operator++() {
    ++cur;
    if (cur == last) {
      set_node(node + 1);
      cur = first;
    }
    return *this;
  }

  self operator++(int) {
    self &tmp = *this;
    ++*this;
    return tmp;
  }

  self &operator--() {
    if (cur == first) {
      set_node(node + 1);
      cur = last;
    }
    --cur;
    return *this;
  }

  self operator--(int) {
    self &tmp = *this;
    ++*this;
    return tmp;
  }

  self &operator+=(difference_type n) {
    difference_type offset = n + (cur - first);
    if (offset >= 0 && offset < static_cast<difference_type>(buf_size()))
      cur += n;
    else {
      difference_type node_offset =
          offset > 0 ? offset / static_cast<difference_type>(buf_size())
                     : -static_cast<difference_type>((-offset - 1) / buf_size);
      set_node(node + node_offset);
      cur = first +
            (offset - node_offset * static_cast<difference_type>(buf_size()));
    }
    return *this;
  }

  self operator+(difference_type n) {
    self tmp = *this;
    return tmp += n;
  }

  self &operator-=(difference_type n) { return *this += -n; }

  self operator-(difference_type n) {
    self tmp = *this;
    return tmp -= n;
  }

  self &operator[](difference_type n) const { return *(*this + n); }

  pointer cur;
  pointer first;
  pointer last;
  map_pointer node;
};

// vector of pointer to buffer
template <typename _Tp, typename _Alloc = std::allocator<_Tp>,
          size_t _BufSz = 0>
class Deque {
 public:
  using value_type = _Tp;
  using pointer = _Tp *;
  using const_pointer = const _Tp *;
  using reference = _Tp &;
  using const_reference = const _Tp &;
  using size_type = size_t;
  using iterator = DequeIterator<_Tp, _BufSz>;
  using map_pointer = pointer *;
  using difference_type = ptrdiff_t;
  iterator begin();
  iterator end();
  size_type size() const;

  //
  // seems like an array with base address start_
  //

  reference operator[](size_type n){
      return start_[static_cast<difference_type>(n)]}

  reference front() {
    return *start_;
  }

  reference back() {
    iterator tmp = finish_;
    --tmp;
    return *tmp;
  }

  size_type size() const { return finish_ - start_; }

  bool empty() const { return finish_ == start_; }

 private:
  iterator start_;
  iterator finish_;
  map_pointer map_;
  size_type map_size_;

  iterator insert_aux(iterator position, const _Tp &x);
};

}  // namespace dtl

#endif  // DTL_DEQUE_H_