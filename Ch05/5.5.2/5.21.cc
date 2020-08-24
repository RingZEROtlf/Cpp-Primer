#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    while (std::cin >> s1) {
        if (!isupper(s1[0])) continue;
        if (s1 == s2) break;
        s2 = s1;
    }
    return 0;
}