#ifndef DTL_TYPE_TRAITS_H_
#define DTL_TYPE_TRAITS_H_

namespace dtl {

struct true_type {
  constexpr static bool value = true;
};

struct false_type {
  constexpr static bool value = false;
};

template <typename T1, typename T2>
struct is_same_type : false_type {};

template <typename T>
struct is_same_type<T, T> : true_type {};

}  // namespace dtl

#endif  // DTL_TYPE_TRAITS_H_