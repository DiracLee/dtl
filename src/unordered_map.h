#include <memory>

#ifndef DTL_UNORDERED_MAP_H_
#define DTL_UNORDERED_MAP_H_

namespace dtl {

#include "hashtable.h"

template <typename T, typename Hash = hash<T>, typename EqPred = ::std::equal_to<T>,
          typename Alloc = ::std::allocator<T>>
class UnorderedMap {};
}  // namespace dtl

#endif  // DTL_UNORDERED_MAP_H_