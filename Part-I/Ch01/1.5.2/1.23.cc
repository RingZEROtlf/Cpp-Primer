#include <iostream>
#include <map>
#include "../common/Sales_item.h"

int main()
{
    std::map<std::string, int> counter;
    Sales_item trans;
    while (std::cin >> trans) {
        counter[trans.isbn] += 1;
    }
    for (auto&& entry: counter) {
        std::cout << entry.first << ' ' << entry.second << '\n';
    }
    return 0;
}