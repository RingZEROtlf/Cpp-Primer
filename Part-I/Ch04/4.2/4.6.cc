#include <iostream>

int main()
{
    int value;
    std::cin >> value;
    if (value % 2 == 1) {
        std::cout << "odd\n";
    } else {
        std::cout << "even\n";
    }
    return 0;
}