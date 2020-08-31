#include <iostream>

std::istream& read_from_stream(std::istream& is)
{
    auto old_state = is.rdstate();
    char ch;
    while (is >> ch) {
        std::cout << ch;
    }
    is.setstate(old_state);
    return is;
}

int main()
{
    read_from_stream(std::cin);
    return 0;
}