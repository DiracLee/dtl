#ifndef DTL_MULTI_MAP_H_
#define DTL_MULTI_MAP_H_

#include <algorithm>
#include <memory>

#include "rb_tree.h"

namespace dtl {

template <typename Key, typename Compare = std::less<Key>,
          typename Alloc = std::allocator<Key> >
class MultiMap {
 public:
  using key_type = Key;
  using data_type = T;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;

  using key_compare = Compare;

  using iterator = typename rep_type::iterator;

  struct select1st : std::unary_function<value_type, Key> {
    const Key& operator()(const value_type& x) const { return x.first; }
  }

  using rep_type = dtl::RBTree<key_type, value_type, select1st<value_type>,
                               key_compare, Alloc>;

 private:
  rep_type t;
};

}  // namespace dtl

#endif  // DTL_MULTI_MAP_H_