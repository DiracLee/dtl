// # include <hashtable.h>

#ifndef DTL_HASHTABLE_H_
#define DTL_HASHTABLE_H_

#include <iterator>
#include <vector>
#include <memory>


namespace dtl {

template <typename Value>
struct HashtableNode {
  HashtableNode *next;
  Value val;
};

template <typename Value,       // key + data
          typename Key,         // key
          typename HashFunc,    // hash function: object => number
          typename ExtractKey,  // how to get key from value
          typename EqualKey,    // define key1 == key2
          typename Alloc>
class Hashtable {
 public:
  using hasher = HashFunc;
  using key_equal = EqualKey;
  using key_type = Key;
  using size_type = size_t;

  size_type bucket_count() const { return buckets.size(); }

  size_type bkt_num_key(const key_type &key, size_type n) const {
    return hash(key) % n;
  }

 private:
  hasher hash;
  key_equal equals;
  ExtractKey get_key;

  using node = HashtableNode<Value>;

  ::std::vector<node *, Alloc> buckets;

  size_type num_elements;

  static const unsigned long kPrimeList[] = {
      53,        97,         193,          389,       769,       1543,
      3079,      6151,       12289,        24593,     49157,     98317,
      196613,    393241,     786433,       1572869,   3156739,   6291469,
      12582917,  25165843,   50331653,     100663319, 201326611, 402653189,
      805306457, 1610612741, 3221225473ul, 4294967};
};

template <typename Value,       // key + data
          typename Key,         // key
          typename HashFunc,    // hash function
          typename ExtractKey,  // how to get key from value
          typename EqualKey,    // define key1 == key2
          typename Alloc>
class HashtableIterator {
  using node = HashtableNode<Value>;
  Hashtable *ht;

  node *cur;
};

}  // namespace dtl

#endif  // DTL_HASHTABLE_H_