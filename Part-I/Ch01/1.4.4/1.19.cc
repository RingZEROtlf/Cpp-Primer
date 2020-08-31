#include <iostream>
#include <algorithm>

int main()
{
    int a, b;
    std::cout << "Input two values a, b (a <= b): ";
    std::cin >> a >> b;
    if (a > b) {
        std::swap(a, b);
    }
    while (a <= b) {
        std::cout << a << '\n';
        a++;
    }
    return 0;
}