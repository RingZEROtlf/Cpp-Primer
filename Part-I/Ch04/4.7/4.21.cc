#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto &v: vec) {
        v = (v % 2 == 1 ? v * 2 : v);
    }
    return 0;
}