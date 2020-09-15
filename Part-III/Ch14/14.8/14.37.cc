#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
struct IsEqual
{
    bool operator()(const T &a, const T &b)
    {
        return a == b;
    }
};

int main()
{
    std::vector<int> vec { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 1, 0 };
    std::replace_if(vec.begin(), vec.end(), 
                    std::bind(::IsEqual<int>(), std::placeholders::_1, 1), 100);
    for (auto &v: vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}