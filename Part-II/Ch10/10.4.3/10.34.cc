#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    ostream_iterator<int> out(cout, " ");
    copy(vec.rbegin(), vec.rend(), out);
    cout << endl;
    return 0;
}