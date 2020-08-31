#include <iostream>

int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *p1 = &a[2], *p2 = &a[5];
    p1 += p2 - p1; // p1 = p2, legal

    int *p3 = &a[5], *p4 = &a[2];
    p3 += p4 - p3; // illegal
    return 0;
}