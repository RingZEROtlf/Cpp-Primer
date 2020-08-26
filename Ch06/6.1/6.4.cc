#include <iostream>

int fact(int n)
{
    return n <= 1 ? 1 : n * fact(n - 1);
}

int main()
{
    std::cout << "Please enter a number: ";
    int value;
    std::cin >> value;
    std::cout << "The factorial of the number is: " << fact(value) << std::endl;
    return 0;
}