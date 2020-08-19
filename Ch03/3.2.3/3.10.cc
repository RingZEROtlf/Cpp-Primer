#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    std::cin >> s;
    for (auto &c: s) {
        if (!ispunct(c)) {
            std::cout << c;
        }
    }
    std::cout << '\n';
    return 0;
}