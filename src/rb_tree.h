#ifndef DTL_RB_TREE_H_
#define DTL_RB_TREE_H_

#include "memory"

namespace dtl {

enum RBTreeColor { RED, BLACK };

template <typename Value>
struct RBTreeNode {
  using pointer = RBTreeNode<Value>;

  pointer parent;
  pointer left;
  pointer right;
};

template <typename Key,         // key
          typename Value,       // key + data
          typename KeyOfValue,  // how to get key from value
          typename Compare,     // how to compare two keys
          typename Alloc = ::std::allocator<Value>>
class RBTree {
 public:
  using size_type = size_t;
  using rb_tree_node = RBTreeNode<Value>;
  using link_type = rb_tree_node*;

 private:
  size_type node_count;
  link_type header;
  Compare key_compare;
};

}  // namespace dtl

#endif  // DTL_RB_TREE_H_