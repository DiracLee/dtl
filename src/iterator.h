#ifndef DTL_ITERATOR_H_
#define DTL_ITERATOR_H_

#include <iterator>

#include "type.h"

namespace dtl {

template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
          typename _Pointer = _Tp*, typename _Reference = _Tp&>
struct Iterator {
  using iterator_category = _Category;
  using value_type = _Tp;
  using difference_type = _Distance;
  using pointer = _Pointer;
  using reference = _Reference;
};

template <typename _Iterator>
struct ReverseIterator
    : public Iterator<
          typename ::std::iterator_traits<_Iterator>::iterator_category,
          typename ::std::iterator_traits<_Iterator>::value_type,
          typename ::std::iterator_traits<_Iterator>::difference_type,
          typename ::std::iterator_traits<_Iterator>::pointer,
          typename ::std::iterator_traits<_Iterator>::reference> {
 public:
  using iterator_category =
      typename ::std::iterator_traits<_Iterator>::iterator_category;
  using value_type = typename ::std::iterator_traits<_Iterator>::value_type;
  using difference_type =
      typename ::std::iterator_traits<_Iterator>::difference_type;
  using pointer = typename ::std::iterator_traits<_Iterator>::pointer;
  using reference = typename ::std::iterator_traits<_Iterator>::reference;

  using iterator_type = _Iterator;
  using self = ReverseIterator<_Iterator>;

  ReverseIterator() : current() {}

  ReverseIterator(iterator_type x) : current(x) {}

  ReverseIterator(const self& x) : current(x.current) {}

  template <typename _Iter>
  ReverseIterator(const ReverseIterator<_Iter>& x) : current(x.base()) {}

  iterator_type base() const { return current; }

  reference operator*() const;

  pointer operator->() const;

  self& operator++();

  self operator++(int);

  self& operator--();

  self operator--(int);

  self operator+(difference_type n) const;

  self operator-(difference_type n) const;

  self& operator-=(difference_type n) const;

  self operator[](difference_type n) const;

 protected:
  iterator_type current;
};

}  // namespace dtl

#endif  // DTL_ITERATOR_H_