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
        auto p1 = make_pair(s, i);
        pair<string, int> p2(s, i);
        vec.push_back( { s, i } );
    }
    return 0;
}