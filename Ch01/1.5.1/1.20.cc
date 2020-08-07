#include <iostream>
#include "../common/Sales_item.h"

int main()
{
    Sales_item trans;
    while (std::cin >> trans) {
        std::cout << trans;
    }
    return 0;
}