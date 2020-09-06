#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec { 1, 2, 1, 2, 1, 3 };
    std::cout << std::count(vec.begin(), vec.end(), 2) << std::endl;
    return 0;
}