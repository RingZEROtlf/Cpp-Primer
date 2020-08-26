#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s = "";
    s += argv[0];
    s += argv[1];
    std::cout << s << std::endl;
    return 0;
}