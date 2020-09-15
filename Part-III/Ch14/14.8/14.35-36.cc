#include <string>
#include <iostream>
#include <vector>

struct PrintString
{
    std::string operator()(std::istream &is)
    {
        std::string s;
        try {
            std::getline(is, s);
            return s;
        } catch (std::exception &e) {
            return "";
        }
    }
};

int main()
{
    std::vector<std::string> vec;
    PrintString ps;
    while (true) {
        vec.push_back(ps(std::cin));
    }
    return 0;
}