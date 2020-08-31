#include <iostream>
#include <limits>

int main()
{
    std::cout << std::numeric_limits<int>::min() - 1 << std::endl;
    std::cout << std::numeric_limits<int>::max() + 1 << std::endl;
    std::cout << std::numeric_limits<double>::max() * std::numeric_limits<double>::max() << std::endl;
    return 0;
}