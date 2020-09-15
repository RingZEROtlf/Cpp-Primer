#include <iostream>
#include <fstream>
#include <string>

struct IsFixedLength
{
    std::string::size_type length;

    IsFixedLength() : length(0) {}
    IsFixedLength(std::string::size_type length) : length(length) {}

    bool operator()(const std::string &str)
    {
        return str.length() == length;
    }
};

int main()
{
    std::ifstream fin("input.txt");
    std::string word;
    IsFixedLength checker[10];
    for (std::size_t i = 0; i < 10; ++i) {
        checker[i] = IsFixedLength(i + 1);
    }
    std::size_t counter[10] = { 0 };
    while (fin >> word) {
        for (std::size_t i = 0; i < 10; ++i) {
            if (checker[i](word)) {
                ++counter[i];
            }
        }
    }
    for (std::size_t i = 0; i < 10; ++i) {
        std::cout << counter[i] << std::endl;
    }
    return 0;
}