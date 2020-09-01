#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<char> vec { 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!' };
    string s(vec.begin(), vec.end());
    cout << s << "\n";
    return 0;
}