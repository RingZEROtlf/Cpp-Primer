#include <iostream>
#include <string>

int main()
{
    std::string s = "4tzdvasgaSFS";

    for (char &c: s) {
        c = 'X';
    }
    std::cout << s << '\n';
}