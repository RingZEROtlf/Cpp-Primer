#include <iostream>

int main()
{
    char _char;
    short _short;
    int _int;
    long _long;
    long long _long_long;
    float _float;
    double _double;

    std::cout << (sizeof _char) << std::endl;
    std::cout << (sizeof _short) << std::endl;
    std::cout << (sizeof _int) << std::endl;
    std::cout << (sizeof _long) << std::endl;
    std::cout << (sizeof _long_long) << std::endl;
    std::cout << (sizeof _float) << std::endl;
    std::cout << (sizeof _double) << std::endl;

    return 0;
}