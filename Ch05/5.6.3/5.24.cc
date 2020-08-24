#include <iostream>
#include <stdexcept>

int main()
{
    int a, b;
    std::cin >> a >> b;
    if (b == 0) {
        throw std::runtime_error("divisor should not be zero!");
    } else {
        std::cout << a / b << std::endl;
    }
    return 0;
}