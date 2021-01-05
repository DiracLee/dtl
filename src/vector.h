#ifndef DTL_VECTOR_H_
#define DTL_VECTOR_H_

namespace dtl {

// Dynamic array-like contrainer of templates
template <typename _Tp, typename _Alloc = ::std::allocator<_Tp>>
class Vector {
 public:
  using value_type = _Tp;
  using pointer = _Tp *;
  using const_pointer = const _Tp *;
  using reference = _Tp &;
  using const_reference = const _Tp &;
  using size_type = size_t;
  using iterator = _Tp *;
  using data_allocator = _Alloc;

  iterator begin();
  iterator end();
  size_type size() const;
  size_type capacity() const;
  bool empty() const;
  reference operator[](size_type n);
  reference front();
  reference bask();

 private:
  iterator start_;
  iterator finish_;
  iterator end_of_storage_;

  void insert_aux(iterator position, const _Tp &x);
  void allocate();
  void deallocate();
};

}  // namespace dtl

#endif  // DTL_VECTOR_H_