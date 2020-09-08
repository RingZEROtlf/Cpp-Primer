#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    auto sz = s.length();
    auto ss = new char[sz + 1];
    for (decltype(sz) idx = 0; idx < sz; ++idx) {
        ss[idx] = s[idx];
    }
    ss[sz] = '\0';
    cout << ss << endl;
    return 0;
}