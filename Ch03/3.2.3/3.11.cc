#include <iostream>
#include <string>

int main()
{
    const std::string s = "Keep out!";
    for (auto &c: s) {
        /* ... */
    }
    return 0;
}