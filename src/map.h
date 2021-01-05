#ifndef DTL_MAP_H_
#define DTL_MAP_H_

#include <algorithm>
#include <memory>

#include "rb_tree.h"

namespace dtl {

template <typename Key, typename T, typename Compare = ::std::less<Key>,
          typename Alloc = ::std::allocator<Key> >
class Map {
 public:
  using key_type = Key;
  using data_type = T;
  using mapped_type = T;
  using value_type = ::std::pair<const Key, T>;

  using key_compare = Compare;

  using iterator = typename rep_type::iterator;

  struct select1st : ::std::unary_function<value_type, Key> {
    const Key& operator()(const value_type& x) const { return x.first; }
  }

  using rep_type = dtl::RBTree<key_type, value_type, select1st<value_type>,
                               key_compare, Alloc>;


  mapped_type &operator[](const key_type& k) {
    iterator iter = lower_bound(k);  // 二分查找，大于等于k的最小位置

    if (iter == end() || key_compare()(k, (*iter).first))
      iter = insert(iter, value_type(k, mapped_type()));
    
    return (*iter).second;
  }

 private:
  rep_type t;
};

}  // namespace dtl

#endif  // DTL_MAP_H_