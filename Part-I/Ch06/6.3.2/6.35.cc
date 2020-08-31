#include <iostream>

int factorial(int val)
{
    if (val > 1)
        return factorial(val--) * val;
    else
        return 1;
}

int main()
{
    std::cout << factorial(5) << std::endl;
    return 0;
}