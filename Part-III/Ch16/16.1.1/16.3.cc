#include <functional>
#include <iostream>
#include "../../../Part-I/Ch07/common/Sales_data.h"

template <typename T> int compare(const T &v1, const T &v2)
{
    if (std::less<T>()(v1, v2)) return -1;
    if (std::less<T>()(v2, v1)) return 1;
    return 0;
}

int main()
{
    Sales_data d1, d2;
    std::cout << compare(d1, d2) << std::endl;
}