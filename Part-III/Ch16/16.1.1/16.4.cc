#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename Iter, typename T>
Iter find(Iter first, Iter last, const T &value)
{
    for (auto iter = first; iter != last; ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return last;
}

int main()
{
    std::vector<int> vec { 1, 2, 3, 100, 4, 5 };
    if (::find(vec.begin(), vec.end(), 100) != vec.end()) {
        std::cout << "found 100 in vector" << std::endl;
    } else {
        std::cout << "not found 100 in vector" << std::endl;
    }
    if (::find(vec.begin(), vec.end(), 1000) != vec.end()) {
        std::cout << "found 1000 in vector" << std::endl;
    } else {
        std::cout << "not found 1000 in vector" << std::endl;
    }

    std::list<std::string> lst { "123", "321" };
    if (::find(lst.begin(), lst.end(), "123") != lst.end()) {
        std::cout << "found '123' in list" << std::endl;
    } else {
        std::cout << "not found '123' in list" << std::endl;
    }
    if (::find(lst.begin(), lst.end(), "1234") != lst.end()) {
        std::cout << "found '1234' in list" << std::endl;
    } else {
        std::cout << "not found '1234' in list" << std::endl;
    }

    return 0;
}