#include <iostream>

int main()
{
    unsigned long ul1 = 3, ul2 = 7;
    std::cout << (ul1 & ul2) << std::endl;
    std::cout << (ul1 | ul2) << std::endl;
    std::cout << (ul1 && ul2) << std::endl;
    std::cout << (ul1 || ul2) << std::endl;
    return 0;
}