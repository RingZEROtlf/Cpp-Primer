#include <iostream>
#include <vector>
#include <algorithm>

bool check(int value, std::vector<int> &vec)
{
    auto it = std::find_if_not(vec.begin(), vec.end(), [=](int a) {
        return value % a == 0;
    });
    return it == vec.end();
}

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    std::cout << check(120, vec) << std::endl;
    std::cout << check(121, vec) << std::endl;
    return 0;
}