template <typename T>
struct remove_reference {
  using type = T;
};

template <typename T>
struct remove_reference<T&> {
  using type = T;
};

template <typename T>
struct remove_reference<T&&> {
  using type = T;
};

template <typename T>
using remove_reference_t = typename remove_reference<T>::type;

template <typename T>
constexpr T&& forward(remove_reference_t<T>& t) noexcept
{
  return static_cast<T&&>(t);
}

template <typename T>
constexpr T&& forward(remove_reference_t<T>&& t) noexcept
{
  return static_cast<T&&>(t);
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
  f(forward<T2>(t2), forward<T1>(t1));
}