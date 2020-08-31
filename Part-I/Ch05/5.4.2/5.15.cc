#include <iostream>

void a()
{
    for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
        // ...
}

void b()
{
    int ix;
    for (ix != sz; ++ix) { /* ... */ }
}

void c()
{
    for (int ix= 0; ix != sz; ++ix, ++sz) { /* ... */ }
}

int main()
{
    return 0;
}