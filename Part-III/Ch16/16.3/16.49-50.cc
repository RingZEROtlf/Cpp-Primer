#include <iostream>

template <typename T> void f(T)
{
  std::cout << "void f(T)" << std::endl;
}
template <typename T> void f(const T*)
{
  std::cout << "void f(const T*)" << std::endl;
}
template <typename T> void g(T)
{
  std::cout << "void g(T)" << std::endl;
}
template <typename T> void g(T*)
{
  std::cout << "void g(T*)" << std::endl;
}

int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;

int main()
{
  g(42);
  g(p);
  g(ci);
  g(p2);
  f(42);
  f(p);
  f(ci);
  f(p2);
}