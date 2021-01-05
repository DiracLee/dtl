#ifndef DTL_LIST_H_
#define DTL_LIST_H_

#include <iterator>

namespace dtl {

template <typename _Tp>
struct ListNode {
  using pointer = ListNode<_Tp> *;

  pointer next;
  pointer prev;
  _Tp data;
};

template <typename _Tp>
struct ListIterator {
  using iterator_category = ::std::bidirectional_iterator_tag;
  using value_type = _Tp;
  using pointer = _Tp *;
  using reference = _Tp &;
  using difference_type = ptrdiff_t;
  
  using link_type = ListNode<_Tp> *;
  using self = ListIterator<_Tp>;

  link_type node_;

  self &operator++();
  self operator++(int);

  self &operator--();
  self operator--(int);

  reference operator*() const;
  pointer operator->() const;
};

template <typename _Tp, typename _Alloc = ::std::allocator<_Tp>>
class List {
 public:
  using data_type = _Tp;
  using list_node = ListNode<_Tp>;
  using link_type = list_node *;
  using iterator = ListIterator<_Tp>;

  List(/* args */);
  ~List();

  iterator begin();  // node_->next
  iterator end();    // node_

 private:
  link_type node_;  // dummy node
};

}  // namespace dtl

#endif  // DTL_LIST_H_