#include <iostream>

void invalid()
{
    int null = 0, *p = null;
}

void valid()
{
    const int null = 0;
    int *p = null;
}

int main()
{
    return 0;
}