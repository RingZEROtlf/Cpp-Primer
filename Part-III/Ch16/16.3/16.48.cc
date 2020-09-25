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