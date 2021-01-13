#ifndef DTL_VECTOR_H_
#define DTL_VECTOR_H_

#include <initializer_list>

#include "iterator.h"
#include "iterator_traits.h"
#include "type.h"
#include "type_traits.h"

namespace dtl {

// Dynamic array-like contrainer of templates
template <typename _Tp>
class Vector {
 public:
  using value_type = _Tp;
  using pointer = _Tp *;
  using const_pointer = const _Tp *;
  using reference = _Tp &;
  using const_reference = const _Tp &;
  using size_type = size_t;

  using iterator = _Tp *;
  using const_iterator = const _Tp *;
  using reverse_iterator = ReverseIterator<iterator>;
  using const_reverse_iterator = ReverseIterator<const_iterator>;

  using self_type = Vector<_Tp>;

  //========================================================================================
  ///                               Default constructor
  ///
  Vector();

  //========================================================================================
  ///                               Copy constructor
  ///
  /// @param    other: the from-vector to copy
  ///
  Vector(const Vector<_Tp> &other);

  //========================================================================================
  ///                               Move constructor
  ///
  /// @param    other: the from-vector to steal
  ///
  Vector(Vector<_Tp> &&other);

  //========================================================================================
  ///                               Constructor
  ///
  /// @param    n: the initial size of this vector
  ///
  explicit Vector(size_type n);

  //========================================================================================
  ///                               Constructor
  ///
  /// @param    n: the initial size of this vector
  /// @param    v: the default value to initialize this vector
  ///
  explicit Vector(size_type n, value_type v);

  //========================================================================================
  ///                               Constructor
  /// Description:
  ///           Copy without the last element of the from-sequence
  ///
  /// @param    first: the iterator to the first element of the from-sequence
  /// @param    last: the iterator to the last element of the from-sequence
  ///
  template <typename _InputIterator>
  Vector(_InputIterator first, _InputIterator last);

  //========================================================================================
  ///                               Constructor
  ///
  /// @param    l: the from-initializer-list
  ///
  Vector(::std::initializer_list<_Tp> l);

  //========================================================================================
  ///                               Destructor
  ///
  ~Vector();

  //========================================================================================
  ///                               Assignment
  ///
  bool operator=(::std::initializer_list<_Tp> l);

  //========================================================================================
  ///                               Copy assignment
  ///
  bool operator=(const self_type &x);

  //========================================================================================
  ///                               Move assignment
  ///
  bool operator=(self_type &&x);

  //========================================================================================
  ///                               Overload opeartor []
  ///
  reference operator[](size_type n);

  //========================================================================================
  ///                               Overload opeartor []
  ///
  const_reference operator[](size_type n) const;

  //========================================================================================
  ///                               Copy and push_back
  ///
  void push_back(const value_type &x);

  //========================================================================================
  ///                               Move to push_back
  ///
  void push_back(value_type &&x);

  //========================================================================================
  ///                               pop_back
  ///
  void pop_back();

  //========================================================================================
  ///                               reserve
  /// Description:
  ///           Reallocate and copy memory if n > than capacity(), otherwise, do
  ///           nothing
  ///
  void reserve(size_type n);

  //========================================================================================
  ///                               resize
  /// Description:
  ///           Change size_ only if new_size < capicity(), otherwise,
  ///           reallocate and copy memory
  ///
  void resize(size_type new_size);

  //========================================================================================
  ///                               resize
  /// Description:
  ///           Change size_ only if new_size < size(), otherwise,
  ///           if new_size < capicity(), fill the new access with x, otherwise,
  ///           reallocate and copy memory
  ///
  void resize(size_type new_size, const value_type &x);

  //========================================================================================
  ///                               shrink_to_fit
  /// Description:
  ///           Reallocate and copy memory to make capicity() == size()
  ///
  void shrink_to_fit();

  //========================================================================================
  ///                               swap
  void swap(const self_type &x);

  //========================================================================================
  ///                               emplace
  /// Description:
  ///           Insert at the position with a value initialized by args
  ///
  template <typename... _Args>
  void emplace(const_iterator position, _Args &&... args);

  //========================================================================================
  ///                               emplace_back
  /// Description:
  ///           Insert as back with a value initialized by args
  ///
  template <typename... _Args>
  void emplace_back(_Args &&... args);

  //========================================================================================
  ///                               insert
  /// Description:
  ///           Insert at the position with values of initializer_list
  ///
  iterator insert(const_iterator position,
                  ::std::initializer_list<value_type> l);

  //========================================================================================
  ///                               insert
  /// Description:
  ///           Insert at the position with values of range [first, last)
  ///
  template <typename _InputIterator>
  iterator insert(const_iterator position, _InputIterator first,
                  _InputIterator last);

  //========================================================================================
  ///                               insert
  /// Description:
  ///           Insert at the position with value copied from x
  ///
  iterator insert(const_iterator position, const value_type &x);

  //========================================================================================
  ///                               insert
  /// Description:
  ///           Insert at the position with value stolen from x
  ///
  iterator insert(const_iterator position, value_type &&x);

  //========================================================================================
  ///                               insert
  /// Description:
  ///           Insert at the position with n values of x
  ///
  iterator insert(const_iterator position, size_type n, const value_type &x);

  //========================================================================================
  ///                               erase
  /// Description:
  ///           Erase range [first, last) of this vector
  ///
  iterator erase(const_iterator first, const_iterator last);

  //========================================================================================
  ///                               erase
  /// Description:
  ///           Erase the element in the position
  ///
  iterator erase(const_iterator position);

  //========================================================================================
  ///                               Range iterators
  ///
  const_iterator begin() const;
  iterator begin();

  const_iterator end() const;

  iterator end();

  //========================================================================================
  ///                               Const range iterators
  ///
  const_iterator cbegin() const;

  const_iterator cend() const;

  //========================================================================================
  ///                               Reverse range iterators
  ///
  const_reverse_iterator rbegin() const;

  reverse_iterator rbegin();

  const_reverse_iterator rend() const;

  reverse_iterator rend();

  //========================================================================================
  ///                               Const reverse range iterators
  ///
  const_reverse_iterator crbegin() const;

  const_reverse_iterator crend() const;

  //========================================================================================
  ///                               assign
  /// Description:
  ///           Reconstruct this vector with initializer_list
  ///
  void assign(::std::initializer_list<_Tp> l);

  //========================================================================================
  ///                               assign
  /// Description:
  ///           Reconstruct this vector with values of range [first, last)
  ///
  template <typename _InputIterator>
  void assign(_InputIterator first, _InputIterator last);

  //========================================================================================
  ///                               assign
  /// Description:
  ///           Reconstruct this vector with n values of v
  ///
  void assign(size_type n, value_type v);

  //========================================================================================
  ///                               at
  /// Description:
  ///           Return const reference of the element indixed by n
  ///
  const_reference at(size_type n) const;

  //========================================================================================
  ///                               at
  /// Description:
  ///           Return reference of the element indixed by n
  ///
  reference at(size_type n);

  //========================================================================================
  ///                               front
  /// Description:
  ///           Return const reference of the front element
  ///
  const_iterator front() const;

  //========================================================================================
  ///                               front
  /// Description:
  ///           Return reference of the front element
  ///
  reference front();

  //========================================================================================
  ///                               back
  /// Description:
  ///           Return const reference of the back element
  ///
  const_reference back() const;

  //========================================================================================
  ///                               back
  /// Description:
  ///           Return reference of the back element
  ///
  reference back();

  //========================================================================================
  ///                               data
  /// Description:
  ///           Return the base pointer of allocated memory
  ///
  pointer data();

  //========================================================================================
  ///                               data
  /// Description:
  ///           Return the base const pointer of allocated memory
  ///
  const_pointer data() const;

  //========================================================================================
  ///                               size
  /// Description:
  ///           Return the count of accessible elements
  ///
  size_type size() const;

  //========================================================================================
  ///                               capacity
  /// Description:
  ///           Return the scale of allocated memory
  ///
  size_type capacity() const;

  //========================================================================================
  ///                               empty
  ///
  bool empty() const;

  //========================================================================================
  ///                               clear
  /// Description:
  ///           Deallocate all memory of data
  /// Caution:
  ///           If data type is pointer, this function won't clear the memory
  ///           that these pointer pointing at, pointer management is user's
  ///           responsibility
  ///
  void clear();

 private:
  iterator start_;  // base pointer of memory allocated
  size_type size_;
  size_type capacity_;

  void insert_aux_(iterator position, const _Tp &x);

  template <typename... _Args>
  void emplace_aux_(const_iterator position, _Args &&... args);

  void emplace_aux_(const_iterator position, value_type &&v);

  void allocate_();

  void deallocate_();
};

//========================================================================================
//                                   API Defination
//========================================================================================

#define DTL_VECTOR_SIZE_TYPE typename Vector<_Tp>::size_type

#define DTL_VECTOR_ITERATOR typename Vector<_Tp>::iterator
#define DTL_VECTOR_CONST_ITERATOR typename Vector<_Tp>::const_iterator

#define DTL_VECTOR_REVERSE_ITERATOR typename Vector<_Tp>::reverse_iterator
#define DTL_VECTOR_CONST_REVERSE_ITERATOR \
  typename Vector<_Tp>::const_reverse_iterator

#define DTL_VECTOR_REFERENCE typename Vector<_Tp>::reference
#define DTL_VECTOR_CONST_REFERENCE typename Vector<_Tp>::const_reference

#define DTL_VECTOR_POINTER typename Vector<_Tp>::pointer
#define DTL_VECTOR_CONST_POINTER typename Vector<_Tp>::const_pointer

//========================================================================================
///                               Default constructor
///
template <typename _Tp>
Vector<_Tp>::Vector() : start_(nullptr), size_(0), capacity_(0) {}

//========================================================================================
///                               Copy constructor
///
/// @param    other: the from-vector to copy
///
template <typename _Tp>
Vector<_Tp>::Vector(const Vector<_Tp> &other)
    : size_(other.size_), capacity_(other.size_) {
  this->start_ = new _Tp[this->capacity_];
  for (size_type i = 0; i < this->size_; ++i)
    *(this->start_ + i) = *(other.start_ + i);
}

//========================================================================================
///                               Move constructor
///
/// @param    other: the from-vector to steal
///
template <typename _Tp>
Vector<_Tp>::Vector(Vector<_Tp> &&other)
    : start_(other.start_), size_(other.size_), capacity_(other.capacity_) {
  other.start_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

//========================================================================================
///                               Constructor
///
/// @param    n: the initial size of this vector
///
template <typename _Tp>
Vector<_Tp>::Vector(size_type n) : size_(n), capacity_(n) {
  this->start_ = new _Tp[this->capacity_];
}

//========================================================================================
///                               Constructor
///
/// @param    n: the initial size of this vector
/// @param    v: the default value to initialize this vector
///
template <typename _Tp>
Vector<_Tp>::Vector(size_type n, value_type v) : size_(n), capacity_(n) {
  this->start_ = new _Tp[this->capacity_];
  for (size_type i = 0; i < this->size_; ++i) *(this->start_ + i) = v;
}

//========================================================================================
///                               Constructor
/// Description:
///           Copy without the last element of the from-sequence
///
/// @param    first: the iterator to the first element of the from-sequence
/// @param    last: the iterator to the last element of the from-sequence
///
template <typename _Tp>
template <typename _InputIterator>
Vector<_Tp>::Vector(_InputIterator first, _InputIterator last)
    : size_(last - first), capacity_(size_) {
  this->start_ = new _Tp[this->capacity_];
  for (size_type i = 0; i < this->size_; ++i)
    *(this->start_ + i) = *(first + i);
}

//========================================================================================
///                               Constructor
///
/// @param    l: the from-initializer-list
///
template <typename _Tp>
Vector<_Tp>::Vector(::std::initializer_list<_Tp> l)
    : size_(l.size()), capacity_(size_) {
  this->start_ = new _Tp[this->capacity_];
  size_type i = 0;
  for (auto v : l) *(this->start_ + i++) = v;
}

//========================================================================================
///                               Destructor
///
template <typename _Tp>
Vector<_Tp>::~Vector() {
  if (this->start_ != nullptr) delete[] this->start_;
  this->start_ = nullptr;
  this->size_ = 0;
  this->capacity_ = 0;
}

//========================================================================================
///                               Assignment
///
template <typename _Tp>
bool Vector<_Tp>::operator=(::std::initializer_list<_Tp> l) {
  this->capacity_ = this->size_ = l.size();
  this->start_ = new _Tp[this->capacity_];
  size_type i = 0;
  for (auto e : l) *(this->start_ + i++) = e;
}

//========================================================================================
///                               Copy assignment
///
template <typename _Tp>
bool Vector<_Tp>::operator=(const self_type &x) {
  this->capacity_ = this->size_ = x.size();
  this->start_ = new _Tp[this->capacity_];
  size_type i = 0;
  for (auto e : x) *(this->start_ + i++) = e;
}

//========================================================================================
///                               Move assignment
///
template <typename _Tp>
bool Vector<_Tp>::operator=(self_type &&x) {
    this->capacity_ = this->size_ = x.size();
  this->start_ = new _Tp[this->capacity_];
  this->start_ = x.start_;

  x.start_ = nullptr;
  x.size_ = 0;
  x.capacity_ = 0;
}

//========================================================================================
///                               Overload opeartor []
///
template <typename _Tp>
DTL_VECTOR_REFERENCE Vector<_Tp>::operator[](size_type n) {
  return *(this->start_ + n);
}

//========================================================================================
///                               Overload opeartor []
///
template <typename _Tp>
DTL_VECTOR_CONST_REFERENCE Vector<_Tp>::operator[](size_type n) const {
  return *(this->start_ + n);
}

//========================================================================================
///                               Copy and push_back
///
template <typename _Tp>
void Vector<_Tp>::push_back(const value_type &x) {}

//========================================================================================
///                               Move to push_back
///
template <typename _Tp>
void Vector<_Tp>::push_back(value_type &&x) {}

//========================================================================================
///                               pop_back
///
template <typename _Tp>
void Vector<_Tp>::pop_back() {}

//========================================================================================
///                               reserve
/// Description:
///           Reallocate and copy memory if n > than capacity(), otherwise, do
///           nothing
///
template <typename _Tp>
void Vector<_Tp>::reserve(size_type n) {}

//========================================================================================
///                               resize
/// Description:
///           Change size_ only if new_size < capicity(), otherwise,
///           reallocate and copy memory
///
template <typename _Tp>
void Vector<_Tp>::resize(size_type new_size) {}

//========================================================================================
///                               resize
/// Description:
///           Change size_ only if new_size < size(), otherwise,
///           if new_size < capicity(), fill the new access with x, otherwise,
///           reallocate and copy memory
///
template <typename _Tp>
void Vector<_Tp>::resize(size_type new_size, const value_type &x) {}

//========================================================================================
///                               shrink_to_fit
/// Description:
///           Reallocate and copy memory to make capicity() == size()
///
template <typename _Tp>
void Vector<_Tp>::shrink_to_fit() {}

//========================================================================================
///                               swap
template <typename _Tp>
void Vector<_Tp>::swap(const self_type &x) {}

//========================================================================================
///                               emplace
/// Description:
///           Insert at the position with a value initialized by args
///
template <typename _Tp>
template <typename... _Args>
void Vector<_Tp>::emplace(const_iterator position, _Args &&... args) {}

//========================================================================================
///                               emplace_back
/// Description:
///           Insert as back with a value initialized by args
///
template <typename _Tp>
template <typename... _Args>
void Vector<_Tp>::emplace_back(_Args &&... args) {}

//========================================================================================
///                               insert
/// Description:
///           Insert at the position with values of initializer_list
///
template <typename _Tp>
DTL_VECTOR_ITERATOR Vector<_Tp>::insert(const_iterator position,
                                        ::std::initializer_list<value_type> l) {
}

//========================================================================================
///                               insert
/// Description:
///           Insert at the position with values of range [first, last)
///
template <typename _Tp>
template <typename _InputIterator>
DTL_VECTOR_ITERATOR Vector<_Tp>::insert(const_iterator position,
                                        _InputIterator first,
                                        _InputIterator last) {}

//========================================================================================
///                               insert
/// Description:
///           Insert at the position with value copied from x
///
template <typename _Tp>
DTL_VECTOR_ITERATOR Vector<_Tp>::insert(const_iterator position,
                                        const value_type &x) {}

//========================================================================================
///                               insert
/// Description:
///           Insert at the position with value stolen from x
///
template <typename _Tp>
DTL_VECTOR_ITERATOR Vector<_Tp>::insert(const_iterator position,
                                        value_type &&x) {}

//========================================================================================
///                               insert
/// Description:
///           Insert at the position with n values of x
///
template <typename _Tp>
DTL_VECTOR_ITERATOR Vector<_Tp>::insert(const_iterator position, size_type n,
                                        const value_type &x) {}

//========================================================================================
///                               erase
/// Description:
///           Erase range [first, last) of this vector
///
template <typename _Tp>
DTL_VECTOR_ITERATOR Vector<_Tp>::erase(const_iterator first,
                                       const_iterator last) {
  if (last != this->end()) ::std::copy(last, this->end(), first);

  this->size_ -= (last - first);
  return first;
}

//========================================================================================
///                               erase
/// Description:
///           Erase the element in the position
///
template <typename _Tp>
DTL_VECTOR_ITERATOR Vector<_Tp>::erase(const_iterator position) {
  if (position + 1 != this->end())
    ::std::copy(position + 1, this->end(), position);

  --this->size_;
  return position;
}

//========================================================================================
///                               Range iterators
///
template <typename _Tp>
DTL_VECTOR_CONST_ITERATOR Vector<_Tp>::begin() const {
  return this->start_;
}

template <typename _Tp>
DTL_VECTOR_ITERATOR Vector<_Tp>::begin() {
  return this->start_;
}

template <typename _Tp>
DTL_VECTOR_CONST_ITERATOR Vector<_Tp>::end() const {
  return this->start_ + this->size_;
}

template <typename _Tp>
DTL_VECTOR_ITERATOR Vector<_Tp>::end() {
  return this->start_ + this->size_;
}

//========================================================================================
///                               Const range iterators
///
template <typename _Tp>
DTL_VECTOR_CONST_ITERATOR Vector<_Tp>::cbegin() const {
  return this->start_;
}

template <typename _Tp>
DTL_VECTOR_CONST_ITERATOR Vector<_Tp>::cend() const {
  return this->start_ + this->size_;
}

//========================================================================================
///                               Reverse range iterators
///
template <typename _Tp>
DTL_VECTOR_CONST_REVERSE_ITERATOR Vector<_Tp>::rbegin() const {
  return reverse_iterator(this->end());
}

template <typename _Tp>
DTL_VECTOR_REVERSE_ITERATOR Vector<_Tp>::rbegin() {
  return reverse_iterator(this->end());
}

template <typename _Tp>
DTL_VECTOR_CONST_REVERSE_ITERATOR Vector<_Tp>::rend() const {
  return reverse_iterator(this->begin());
}

template <typename _Tp>
DTL_VECTOR_REVERSE_ITERATOR Vector<_Tp>::rend() {
  return reverse_iterator(this->begin());
}

//========================================================================================
///                               Const reverse range iterators
///
template <typename _Tp>
DTL_VECTOR_CONST_REVERSE_ITERATOR Vector<_Tp>::crbegin() const {
  return reverse_iterator(this->end());
}

template <typename _Tp>
DTL_VECTOR_CONST_REVERSE_ITERATOR Vector<_Tp>::crend() const {
  return reverse_iterator(this->begin());
}

//========================================================================================
///                               assign
/// Description:
///           Reconstruct this vector with initializer_list
///
template <typename _Tp>
void Vector<_Tp>::assign(::std::initializer_list<_Tp> l) {
  size_type n = l.size();

  if (this->start_ != nullptr) delete[] this->start_;
  this->start_ = new value_type[this->capacity_];

  // if allocate failed, abort
  assert(this->start_ != nullptr);

  this->size_ = this->capacity_ = n;
  DTL_VECTOR_ITERATOR iter = this->begin();
  typename ::std::initializer_list<_Tp>::iterator first = l.begin();
  while (iter != this->end()) *iter++ = *first++;
}

//========================================================================================
///                               assign
/// Description:
///           Reconstruct this vector with values of range [first, last)
///
template <typename _Tp>
template <typename _InputIterator>
void Vector<_Tp>::assign(_InputIterator first, _InputIterator last) {
  // _InputIterator's value type should be the same as _Tp
  using input_value_type =
      typename ::std::iterator_traits<_InputIterator>::value_type;
  assert(::dtl::is_same_type<_Tp, input_value_type>::value);

  size_type n = last - first;

  if (this->start_ != nullptr) delete[] this->start_;
  this->start_ = new value_type[this->capacity_];

  // if allocate failed, abort
  assert(this->start_ != nullptr);

  this->size_ = this->capacity_ = n;

  DTL_VECTOR_ITERATOR iter = this->begin();
  while (iter != this->end()) *iter++ = *first++;
}

//========================================================================================
///                               assign
/// Description:
///           Reconstruct this vector with n values of v
///
template <typename _Tp>
void Vector<_Tp>::assign(size_type n, value_type v) {
  if (this->start_ != nullptr) delete[] this->start_;
  this->start_ = new value_type[n];

  // if allocate failed, abort
  assert(this->start_ != nullptr);

  this->size_ = this->capacity_ = n;

  for (auto iter = this->begin(); iter != this->end(); ++iter) *iter = v;
}

//========================================================================================
///                               at
/// Description:
///           Return const reference of the element indixed by n
///
template <typename _Tp>
DTL_VECTOR_CONST_REFERENCE Vector<_Tp>::at(size_type n) const {
  assert(n < this->size());
  return *(this->start_ + n);
}

//========================================================================================
///                               at
/// Description:
///           Return reference of the element indixed by n
///
template <typename _Tp>
DTL_VECTOR_REFERENCE Vector<_Tp>::at(size_type n) {
  assert(n < this->size());
  return *(this->start_ + n);
}

//========================================================================================
///                               front
/// Description:
///           Return const reference of the front element
///
template <typename _Tp>
DTL_VECTOR_CONST_ITERATOR Vector<_Tp>::front() const {
  assert(!(this->empty()));
  return *(this->start_);
}

//========================================================================================
///                               front
/// Description:
///           Return reference of the front element
///
template <typename _Tp>
DTL_VECTOR_REFERENCE Vector<_Tp>::front() {
  assert(!(this->empty()));
  return *(this->start_);
}

//========================================================================================
///                               back
/// Description:
///           Return const reference of the back element
///
template <typename _Tp>
DTL_VECTOR_CONST_REFERENCE Vector<_Tp>::back() const {
  assert(!(this->empty()));
  return *(this->end() - 1);
}

//========================================================================================
///                               back
/// Description:
///           Return reference of the back element
///
template <typename _Tp>
DTL_VECTOR_REFERENCE Vector<_Tp>::back() {
  assert(!(this->empty()));
  return *(this->end() - 1);
}

//========================================================================================
///                               data
/// Description:
///           Return the base pointer of allocated memory
///
template <typename _Tp>
DTL_VECTOR_POINTER Vector<_Tp>::data() {
  return this->start_;
}

//========================================================================================
///                               data
/// Description:
///           Return the base const pointer of allocated memory
///
template <typename _Tp>
DTL_VECTOR_CONST_POINTER Vector<_Tp>::data() const {
  return this->start_;
}

//========================================================================================
///                               size
/// Description:
///           Return the count of accessible elements
///
template <typename _Tp>
DTL_VECTOR_SIZE_TYPE Vector<_Tp>::size() const {
  return this->size_;
}

//========================================================================================
///                               capacity
/// Description:
///           Return the scale of allocated memory
///
template <typename _Tp>
DTL_VECTOR_SIZE_TYPE Vector<_Tp>::capacity() const {
  return this->capacity_;
}

//========================================================================================
///                               empty
///
template <typename _Tp>
bool Vector<_Tp>::empty() const {
  return this->start_ == nullptr;
}

//========================================================================================
///                               clear
/// Description:
///           Deallocate all memory of data
/// Caution:
///           If data type is pointer, this function won't clear the memory
///           that these pointer pointing at, pointer management is user's
///           responsibility
///
template <typename _Tp>
void Vector<_Tp>::clear() {
  delete[] this->start_;
  this->start_ = nullptr;
  this->size_ = 0;
  this->capacity_ = 0;
}

}  // namespace dtl

#endif  // DTL_VECTOR_H_