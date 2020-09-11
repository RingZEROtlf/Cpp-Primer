#include "String.hpp"
#include <vector>

int main()
{
    std::vector<String> vec;
    // vec.reserve(10);
    for (int i = 0; i < 5; ++i) {
        vec.push_back(String());
    }
    return 0;
}