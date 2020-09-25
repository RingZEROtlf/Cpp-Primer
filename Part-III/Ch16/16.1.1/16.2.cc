#include <functional>
#include <iostream>

template <typename T> int compare(const T &v1, const T &v2)
{
    if (std::less<T>()(v1, v2)) return -1;
    if (std::less<T>()(v2, v1)) return 1;
    return 0;
}

int main()
{
    std::cout << compare(1, 2) << std::endl;
    std::cout << compare(10, 2) << std::endl;
    std::cout << compare(1, 1) << std::endl;

    char arr[5] = { 1, 2, 3, 4, 5 };
    std::cout << compare(&arr[3], &arr[1]) << std::endl;
}