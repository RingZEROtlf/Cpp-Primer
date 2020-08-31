#include <iostream>

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main()
{
    f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}

void f()
{
    std::cout << "void\n";
}

void f(int a)
{
    std::cout << "int\n";
}

void f(int a, int b)
{
    std::cout << "int int\n";
}

void f(double a, double b)
{
    std::cout << "double double\n";
}