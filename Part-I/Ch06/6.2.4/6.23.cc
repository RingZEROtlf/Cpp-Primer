#include <iostream>

void print(int value)
{
    std::cout << value << "\n";
}

void print(int values[], std::size_t size)
{
    for (std::size_t idx = 0; idx < size; ++idx) {
        std::cout << values[idx] << " ";
    }
    std::cout << "\n";
}

int main()
{
    int i = 0, j[2] = { 0, 1 };
    print(i);
    print(j, sizeof(j) / sizeof(j[0]));
    return 0;
}