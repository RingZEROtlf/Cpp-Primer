#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T> string debug_rep(const T &t)
{
  ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T> string debug_rep(T *p)
{
  ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " null pointer";
  return ret.str();
}

string debug_rep(const string &s)
{
  return '"' + s + '"';
}

string debug_rep(char *p)
{
  return debug_rep(string(p));
}

string debug_rep(const char *p)
{
  return debug_rep(string(p));
}

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

template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest)
{
  return print(os, debug_rep(rest)...);
}

int main()
{
  errorMsg(std::cerr, "1", "2", 3, "other", 798);
}