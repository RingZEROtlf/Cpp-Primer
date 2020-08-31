#include <iostream>

int main()
{
    int a = 123;
    int *p = &a;
    if (p) {
        // ...
    }
    if (*p) {
        // ...
    }
    return 0;
}