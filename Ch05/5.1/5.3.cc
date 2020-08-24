#include <iostream>

int main()
{
    int sum = 0, i = 50;
    while (i <= 100) sum += i, i += 1;
    std::cout << sum << '\n';
    return 0;
}