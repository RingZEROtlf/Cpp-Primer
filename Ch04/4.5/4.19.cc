#include <iostream>
#include <vector>

int main()
{
    int *ptr;
    std::vector<int> vec;
    int ival;

    if (ptr != 0 && *ptr++) {}
    if (ival++ && ival) {}
    if (vec[ival++] <= vec[ival]) {}

    return 0;
}