#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    int value;
    while (std::cin >> value) {
        vec.push_back(value);
    }
    for (auto i = vec.begin(), j = vec.end() - 1; i != vec.end(); ++i, --j) {
        std::cout << *i + *j << "\n";
    }
    return 0;
}