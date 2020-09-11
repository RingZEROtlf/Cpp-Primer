#include <iostream>

class numbered
{
    friend void f(numbered);

public:
    numbered() : mysn(counter++) {}
    numbered(const numbered&) : mysn(counter++) {}

private:
    static size_t counter;
    size_t mysn;
};

size_t numbered::counter = 0;

void f(numbered s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
}