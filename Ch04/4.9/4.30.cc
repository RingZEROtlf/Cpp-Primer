#include <iostream>

double f()
{
    return 1.0;
}

int main()
{
    int x, y;
    struct {
        char mem[10];
    } *p;
    float a, b;
    size_t i = 5;
    std::cout << (sizeof x + y) << std::endl;
    std::cout << (sizeof p->mem[i]) << std::endl;
    std::cout << (sizeof a < b) << std::endl;
    std::cout << (sizeof f()) << std::endl;
    return 0;
}