#include <iostream>

int abs(int x)
{
    std::cout << (x >= 0 ? x : -x) << std::endl;
}

int main()
{
    abs(5);
    abs(-4);
    return 0;
}