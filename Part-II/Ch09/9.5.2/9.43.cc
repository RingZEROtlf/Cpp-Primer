#include <iostream>
#include <string>
using namespace std;

void func(string &s, const string &oldVal, const string &newVal)
{
    auto sSize = s.size(), oldSize = oldVal.size(), newSize = newVal.size();
    for (decltype(sSize) idx = 0; idx + oldSize <= sSize; ++idx) {
        auto ss = s.substr(idx, oldSize);
        if (ss == oldVal) {
            s.erase(idx, oldSize);
            s.insert(idx, newVal);
            idx += newSize - 1;
        }
    }
}

int main()
{
    string s = "tho the tho this", oldVal = "tho", newVal = "though";
    func(s, oldVal, newVal);
    cout << s << endl;
    return 0;
}