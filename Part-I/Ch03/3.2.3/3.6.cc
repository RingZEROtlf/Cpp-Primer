#include <iostream>
#include <string>

int main()
{
    std::string s = "4tzdvasgaSFS";

    for (auto &c: s) {
        c = 'X';
    }
    std::cout << s << '\n';
}