#include <iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    // (a) valid
    r2 = 3.14159;

    // (b) valid
    r2 = r1;

    // (c) valid
    i = r2;

    // (d) valid
    r1 = d;

    return 0;
}