#include <iostream>

int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < 10; i++) {
        *(a + i) = 0;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << '\n';
    }
    return 0;
}