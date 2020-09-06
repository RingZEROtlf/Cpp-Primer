#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    vector<pair<string, int>> vec;
    string s;
    int i;
    while (cin >> s >> i) {
        auto p = make_pair(s, i);
        vec.push_back(p);
    }
    return 0;
}