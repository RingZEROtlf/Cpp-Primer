#include <iostream>

void swap_by_pointer(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 3, b = 4;
    std::cout << a << " " << b << std::endl;
    swap_by_pointer(&a, &b);
    std::cout << a << " " << b << std::endl;
    return 0;
}