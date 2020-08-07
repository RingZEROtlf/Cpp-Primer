#include <iostream>
#include "../common/Sales_item.h"

int main()
{
    Sales_item trans, total;
    while (std::cin >> trans) {
        total += trans;
    }
    std::cout << total << '\n';
    return 0;
}