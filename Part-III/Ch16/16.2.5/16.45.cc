#include <vector>

template <typename T> void g(T&& val) { std::vector<T> v; }

int main()
{
  g(42);
  int a = 43;
  g(a);
}