#include <iostream>
#include <vector>

template <typename C>
void f(C &c)
{
    for (typename C::size_type i = 0; i < c.size(); ++i) {
        std::cout << c[i] << std::endl;
    }
}

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    f(vec);
}