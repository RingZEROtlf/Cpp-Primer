#include <iostream>

int main()
{
    // 1.9
    int sum = 0;
    for (int i = 50; i <= 100; i++) {
        sum += i;
    }
    std::cout << sum << '\n';

    // 1.10
    for (int i = 10; i >= 0; i--) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // 1.11
    int a, b;
    std::cout << "Input two values a, b (a <= b): ";
    std::cin >> a >> b;
    for (int i = a; i <= b; i++) {
        std::cout << i << '\n';
    }

    return 0;
}