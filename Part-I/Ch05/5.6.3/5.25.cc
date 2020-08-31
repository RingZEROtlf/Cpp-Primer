#include <iostream>
#include <stdexcept>

int main()
{
    int a, b;
    while (std::cin >> a >> b) {
        try {
            if (b == 0) {
                throw std::runtime_error("divisor should not be zero!");
            } else {
                std::cout << a / b << std::endl;
            }
        } catch (std::exception e) {
            std::cout << e.what() << std::endl
                    << "Try Again? Enter Y or N" << std::endl;
            char c;
            std::cin >> c;
            if (!std::cin || c == 'N')
                break;
        }
    }
    return 0;
}