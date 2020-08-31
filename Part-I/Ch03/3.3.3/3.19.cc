#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1(10, 42);
    std::vector<int> v2{10, 42};
    std::vector<int> v3{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    return 0;
}