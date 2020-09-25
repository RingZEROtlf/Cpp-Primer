#include <iostream>

template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
  return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest)
{
  os << t << ", ";
  return print(os, rest...);
}

struct test {};

int main()
{
  int i = 0; double d = 3.14; std::string s = "how now brown cow";
  print(std::cout, i) << std::endl;
  print(std::cout, i, d) << std::endl;
  print(std::cout, i, d, s, d, i) << std::endl;

  // print(test(), i) << std::endl;
}