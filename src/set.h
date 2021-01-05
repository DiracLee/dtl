#ifndef DTL_SET_H_
#define DTL_SET_H_

#include <algorithm>
#include <memory>

#include "rb_tree.h"

namespace dtl {

template <typename Key, typename Compare = ::std::less<Key>,
          typename Alloc = ::std::allocator<Key> >
class Set {
 public:
  using key_type = Key;
  using value_type = Key;
  using key_compare = Compare;
  using value_compare = Compare;

  using iterator = typename rep_type::const_iterator;

  struct identity : ::std::unary_function<value_type, Key> {
    const Key& operator()(const value_type& x) const { return x; }
  }

  private : using rep_type =
                dtl::RBTree<key_type, value_type, identity<value_type>,
                            key_compare, Alloc>;

  rep_type t;
};

}  // namespace dtl

#endif  // DTL_SET_H_