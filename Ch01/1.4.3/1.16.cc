#include <iostream>

int main()
{
    int a, sum = 0;
    while (std::cin >> a) {
        sum += a;
    }
    std::cout << sum << '\n';
    return 0;
}