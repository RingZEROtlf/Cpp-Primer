#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> lst { 1, 2, 0, 3, 4, 5, 0, 5, 4, 3, 2, 1 };
    auto it = find(lst.rbegin(), lst.rend(), 0);
    return 0;
}