#include <iostream>

int main()
{
    int someValue = 123;
    int x = 3, y = 4;
    std::cout << (someValue ? ++x, ++y : --x, --y) << std::endl;
    return 0;
}