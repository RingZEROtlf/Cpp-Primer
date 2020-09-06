#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    multimap<string, string> works;
    auto range = works.equal_range("123");
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}