#include <iostream>

int main()
{
    // same
    int a = 3;
    auto b = a;
    decltype(a) c = a;

    // different
    const int aa = 4;
    auto bb = aa;
    decltype(aa) cc = aa;

    return 0;
}