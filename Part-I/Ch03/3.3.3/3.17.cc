#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main()
{
    std::vector<std::string> vec;
    std::string word;
    while (std::cin >> word) {
        vec.push_back(word);
    }

    for (auto &word: vec) {
        for (auto &c: word) {
            c = std::toupper(c);
        }
        std::cout << word << "\n";
    }
    return 0;
}