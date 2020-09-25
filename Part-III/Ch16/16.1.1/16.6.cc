#include <iostream>
#include <vector>

template <typename Container>
auto begin(Container &container) -> decltype(container.begin())
{
    return container.begin();
}

template <typename Container>
auto begin(const Container &container) -> decltype(container.begin())
{
    return container.begin();
}

template <typename T, std::size_t N>
T* begin(T (&array)[N]) noexcept
{
    return array;
}

template <typename Container>
auto end(Container &container) -> decltype(container.end())
{
    return container.end();
}

template <typename Container>
auto end(const Container &container) -> decltype(container.end())
{
    return container.end();
}

template <typename T, std::size_t N>
T* end(T (&array)[N]) noexcept
{
    return array + N;
}

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    std::cout << *::begin(vec) << std::endl;
    *::begin(vec) = 123;

    int arr[] = { 5, 4, 2, 3, 1 };
    std::cout << *::begin(arr) << std::endl;
}