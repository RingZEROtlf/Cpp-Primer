#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool has_captical(const string& s)
{
    for (auto &c: s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

void to_lowercase(string& s)
{
    for (auto &c: s) {
        c = tolower(c);
    }
}

int main()
{
    string s = "abcDEF";
    cout << has_captical(s) << endl;
    to_lowercase(s);
    cout << s << endl;
    return 0;
}