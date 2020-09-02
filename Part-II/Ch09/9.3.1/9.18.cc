#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    string s;
    deque<string> dq;
    while (cin >> s) {
        dq.push_back(s);
    }
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}