#include <iostream>

int main()
{
    const int v2 = 0;   // top-level const
    int v1 = v2;        // non const
    int *p1 = &v1, &r1 = v1; // non const
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;

    r1 = v2;
    p1 = p2; p2 = p1;
    p1 = p3; p2 = p3;
    return 0;
}