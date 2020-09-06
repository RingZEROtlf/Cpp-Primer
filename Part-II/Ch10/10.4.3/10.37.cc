#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list<int> lst(vec.rbegin() + 3, vec.rbegin() + 8);
    for (auto &v: lst) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}