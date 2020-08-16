#include <iostream>

void f1()
{
    int month = 9, day = 7;
    std::cout << month << " " << day << "\n";
}

void f2()
{
    int month = 09, day = 07;
    std::cout << month << " " << day << "\n";
}

int main()
{
    f1();
    f2();

    return 0;
}