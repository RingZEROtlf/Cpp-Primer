#include <iostream>

int main()
{
    int a = 123, b = 321;
    int *p = &a;
    *p = 333;
    p = &b;

    return 0;
}