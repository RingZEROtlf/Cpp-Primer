#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    int value;
    while (std::cin >> value) {
        vec.push_back(value);
    }
    return 0;
}