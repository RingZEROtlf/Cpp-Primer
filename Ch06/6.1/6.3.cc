#include <iostream>

int fact(int n)
{
    return n == 1 ? 1 : n * fact(n - 1);
}

int main()
{
    std::cout << fact(5) << std::endl;
    return 0;
}