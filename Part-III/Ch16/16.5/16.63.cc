#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::size_t count_in_vector(const std::vector<T> &vec, const T &val)
{
  return std::count(vec.begin(), vec.end(), val);
}

template <>
std::size_t count_in_vector(const std::vector<const char *> &vec, const char * const &val)
{
  return 0;
}