#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void a()
{
    vector<int> vec; list<int> lst; int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), vec.begin());
}

void b()
{
    vector<int> vec;
    vec.reserve(10);
    fill_n(vec.begin(), 10, 0);
}

int main()
{
    return 0;
}