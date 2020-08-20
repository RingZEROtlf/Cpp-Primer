#include <iostream>

int main()
{
    int i;
    double d;
    d = i = 3.5;
    std::cout << d << " " << i << "\n";
    i = d = 3.5;
    std::cout << d << " " << i << "\n";
    return 0;
}