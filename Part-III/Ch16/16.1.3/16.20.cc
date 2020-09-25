#include <iostream>
#include <vector>

template <typename C>
void f(C &c)
{
    for (typename C::iterator it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    f(vec);
}