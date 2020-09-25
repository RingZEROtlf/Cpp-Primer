#include <iostream>
#include <string>

template <typename T, std::size_t N>
void print(const T (&ia)[N])
{
    for (size_t i = 0; i != N; ++i)
        std::cout << ia[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    std::string arr2[5] = { "1", "2", "3", "4", "5" };
    print(arr1);
    print(arr2);
}