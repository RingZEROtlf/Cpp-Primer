#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << *vec.begin() << std::endl;
    std::cout << *(vec.begin()) << std::endl;
    std::cout << *vec.begin() + 1 << std::endl;
    std::cout << (*(vec.begin())) + 1 << std::endl;
    return 0;
}