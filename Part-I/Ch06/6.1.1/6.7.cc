#include <iostream>

int func()
{
    static int value = 0;
    return value++;
}

int main()
{
    for (int i = 0; i < 5; i++) {
        std::cout << func() << std::endl;
    }
    return 0;
}