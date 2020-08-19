#include <iostream>
#include <vector>

int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> vec(std::begin(a), std::end(a));
    return 0;
}