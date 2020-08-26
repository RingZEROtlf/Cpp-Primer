#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> value_list)
{
    int result = 0;
    for (auto &value: value_list) {
        result += value;
    }
    return result;
}

int main()
{
    std::cout << sum( { 1, 3, 5, 7, 9 } );
    return 0;
}