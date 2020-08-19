#include <iostream>
#include <string>

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1 == s2) {
        std::cout << "the same\n";
    } else {
        std::cout << "different\n";
        std::cout << (s1 > s2 ? s1 : s2) << '\n';
    }

    std::cin >> s1 >> s2;
    if (s1.length() == s2.length()) {
        std::cout << "the same length\n";
    } else {
        std::cout << "different length\n";
        std::cout << (s1.length() > s2.length() ? s1 : s2) << '\n';
    }
    return 0;
}