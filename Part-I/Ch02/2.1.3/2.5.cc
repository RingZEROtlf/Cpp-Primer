#include <iostream>

int main()
{
    std::cout << 'a' << L'a' << "a" << L"a" << std::endl;
    std::cout << 10 << 10u << 10L << 10uL << 012 << 0xC << std::endl;
    std::cout << 3.14 << 3.14f << 3.14L << std::endl;
    std::cout << 10 << 10u << 10. << 10e-2 << std::endl;

    return 0;
}