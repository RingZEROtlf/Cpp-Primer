#include <iostream>

int main()
{
    const char *cp = "Hello World";
    if (cp && *cp) {
        std::cout << "Hi\n";
    }
    return 0;
}