#include <iostream>
#include <string>
using namespace std;

int main()
{
    do {
        cout << "Please enter two strings: ";
        string s1, s2;
        cin >> s1 >> s2;
        cout << (s1.length() < s2.length() ? s1 : s2) << endl;
    } while (false);
    return 0;
}