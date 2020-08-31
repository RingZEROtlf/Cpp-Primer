#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    int value;
    while (std::cin >> value) {
        vec.push_back(value);
    }
    for (int i = 0, j = vec.size() - 1; i < vec.size(); i++, j--) {
        std::cout << vec[i] + vec[j] << "\n";
    }
    return 0;
}