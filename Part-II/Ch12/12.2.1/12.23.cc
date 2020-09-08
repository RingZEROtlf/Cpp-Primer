#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char* concatenate_chars(const char *s1, const char *s2)
{
    size_t sz1 = strlen(s1), sz2 = strlen(s2);
    char* res = new char[sz1 + sz2 + 1];
    for (size_t idx = 0; idx < sz1 + sz2; ++idx) {
        if (idx < sz1) {
            res[idx] = s1[idx];
        } else {
            res[idx] = s2[idx - sz1];
        }
    }
    res[sz1 + sz2] = '\0';
    return res;
}

string concatenate_strings(const string &s1, const string &s2)
{
    return s1 + s2;
}

int main()
{
    const char *s1 = "123", *s2 = "456";
    cout << concatenate_chars(s1, s2) << endl;
    string ss1 = "321", ss2 = "654";
    cout << concatenate_strings(ss1, ss2) << endl;
    return 0;
}