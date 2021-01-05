#include <memory>

#ifndef DTL_UNORDERED_MULTIMAP_H_
#define DTL_UNORDERED_MULTIMAP_H_

namespace dtl {

#include "hashtable.h"


template <typename T, typename Hash = ::std::hash<T>, typename EqPred = ::std::equal_to<T>,
          typename Alloc = ::std::allocator<T>>
class UnorderedMultimap {};
}  // namespace dtl

#endif  // DTL_UNORDERED_MULTIMAP_H_