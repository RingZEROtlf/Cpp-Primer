#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> vec;
    std::string s;
    while (std::cin >> s) {
        vec.push_back(s);
    }
    return 0;
}