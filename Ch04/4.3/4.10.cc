#include <iostream>

int main()
{
    int value;
    while (std::cin >> value && value != 42) {}
    return 0;
}