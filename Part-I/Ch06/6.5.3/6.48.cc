#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main()
{
    string sought = "to be sought";
    string s;
    while (cin >> s && s != sought) //
        assert(cin);
    return 0;
}