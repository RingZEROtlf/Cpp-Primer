#include <iostream>
#include <string>
using namespace std;

bool _is_empty(string& s)
{
    return s.empty();
}

int main()
{
    string s = "123";
    _is_empty(s);
    _is_empty("321");
    return 0;
}