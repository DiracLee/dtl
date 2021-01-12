#ifndef DTL_ITERATOR_TRAITS_H_
#define DTL_ITERATOR_TRAITS_H_

#include "type.h"

namespace dtl {

struct input_iterator_tag {};

struct output_iterator_tag {};

struct forward_iterator_tag : public input_iterator_tag {};

struct bidirectional_iterator_tag : public forward_iterator_tag {};

struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <typename _Iterator>
struct iterator_traits {
  using iterator_category = typename _Iterator::iterator_category;
  using difference_type = typename _Iterator::difference_type;
  using value_type = typename _Iterator::value_type;
  using reference = typename _Iterator::reference;
  using pointer = typename _Iterator::pointer;
};

template <typename _Tp>
struct iterator_traits<_Tp *> {
  using iterator_category = ::dtl::random_access_iterator_tag;
  using difference_type = ::dtl::ptrdiff_t;
  using value_type = _Tp;
  using reference = _Tp &;
  using pointer = _Tp *;
};

}  // namespace dtl

#endif  // DTL_ITERATOR_TRAITS_H_