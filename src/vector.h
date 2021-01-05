#ifndef DTL_VECTOR_H_
#define DTL_VECTOR_H_

#include <initializer_list>

#include "iterator.h"
#include "type.h"

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
  Vector(size_type n);

  //========================================================================================
  ///                               Constructor
  ///
  /// @param    n: the initial size of this vector
  /// @param    v: the default value to initialize this vector
  ///
  Vector(size_type n, value_type v);

  //========================================================================================
  ///                               Constructor
  /// Description:
  ///           Copy without the last element of the from-sequence
  ///
  /// @param    first: the iterator to the first element of the from-sequence
  /// @param    last: the iterator to the last element of the from-sequence
  ///
  template <typename InputIterator>
  Vector(InputIterator first, InputIterator last);

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
  ///           Move finish_ only if new_size < capicity(), otherwise,
  ///           reallocate and copy memory
  ///
  void resize(size_type new_size);

  //========================================================================================
  ///                               resize
  /// Description:
  ///           Move finish_ only if new_size < size(), otherwise,
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
  template <typename InputIterator>
  void assign(InputIterator first, InputIterator last);

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
  iterator start_;           // base pointer of memory allocated
  iterator finish_;          // pointer to the next memory of last element
  iterator end_of_storage_;  // upper bound of memory allocated

  void insert_aux_(iterator position, const _Tp &x);

  template <typename... _Args>
  void emplace_aux_(const_iterator position, _Args &&... args);

  void emplace_aux_(const_iterator position, value_type &&v);

  void allocate_();

  void deallocate_();
};

}  // namespace dtl

#endif  // DTL_VECTOR_H_