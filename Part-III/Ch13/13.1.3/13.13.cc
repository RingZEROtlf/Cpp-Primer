#include <iostream>
#include <string>
#include <vector>

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X& x)
    {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
};

void f1(X &x) {}
void f2(X x) {}

X f3() {
    X x;
    return x;
}

int main()
{
    X x;
    // f1(x);
    // f2(x);

    std::vector<X> vec;
    vec.reserve(10);
    vec.push_back(x);
    vec.push_back(x);

    X x2(x), x3 = x;
    x2 = x;

    // X x4 = f3();
    x3 = f3();

    return 0;
}