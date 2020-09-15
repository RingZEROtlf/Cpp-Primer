#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

auto a(std::vector<int> &vec)
{
    return std::count_if(vec.begin(), vec.end(),
        std::bind(std::greater<int>(), std::placeholders::_1, 1024));
}

std::string b(std::vector<std::string> &vec)
{
    auto it = std::find_if(vec.begin(), vec.end(),
        std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh"));
    return it == vec.end() ? "" : *it;
}

void c(std::vector<int> &vec)
{
    std::for_each(vec.begin(), vec.end(), [](int &a) {
        a *= 2;
    });
}

int main()
{
    std::vector<int> va { 1, 2, 3, 4, 1025, 7, 10000 };
    std::cout << a(va) << std::endl;

    std::vector<std::string> vb { "pooh", "pooh", "123", "pooh", "321", "asdfa" };
    std::cout << b(vb) << std::endl;

    std::vector<int> vc { 1, 2, 3, 4, 5 };
    c(vc);
    for (auto &v: vc) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}