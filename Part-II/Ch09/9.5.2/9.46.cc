#include <iostream>
#include <string>
using namespace std;

string func(const string &name, const string &prefix, const string &postfix)
{
    auto s = name;
    s.insert(s.size(), " ");
    s.insert(s.size(), postfix);
    s.insert(0, prefix + " ");
    return s;
}

int main()
{
    cout << func("Bill", "Saint", "the Killer") << endl;
    return 0;
}