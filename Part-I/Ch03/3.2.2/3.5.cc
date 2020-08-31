#include <iostream>
#include <vector>
#include <string>

std::string join(std::vector<std::string> &vec, std::string sep)
{
    std::string s = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        s += sep + vec[i];
    }
    return s;
}

int main()
{
    std::vector<std::string> vec;
    std::string s;
    while (std::cin >> s) {
        vec.push_back(s);
    }

    std::cout << join(vec, "") << '\n';
    std::cout << join(vec, " ") << '\n';
    return 0;
}