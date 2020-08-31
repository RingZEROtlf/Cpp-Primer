#include <iostream>
#include "../common/Sales_item.h"

int main()
{
    Sales_item trans1, trans2;
    std::cin >> trans1 >> trans2;
    std::cout << trans1 + trans2 << '\n';
    return 0;
}