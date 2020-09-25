#include <iostream>

template <typename T, std::size_t N>
constexpr std::size_t get_size(T (&array)[N])
{
    return N;
}

int main()
{
    int arr[5];
    std::cout << ::get_size(arr) << std::endl;
}