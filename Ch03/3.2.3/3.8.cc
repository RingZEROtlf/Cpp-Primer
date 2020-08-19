#include <iostream>
#include <string>

int main()
{
    std::string s = "4tzdvasgaSFS";

    for (std::string::size_type idx = 0; idx < s.length(); idx++) {
        s[idx] = 'X';
    }
    std::cout << s << '\n';

    s = "12341zxcbaet";
    std::string::size_type idx = 0;
    while (idx < s.length()) {
        s[idx] = 'X';
        idx++;
    }
    std::cout << s << '\n';

    return 0;
}