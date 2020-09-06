#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec { 1, 1, 2, 2, 3, 4, 56, 7, 8, 1, 9 };
    list<int> lst;
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    for (auto &v: lst) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}