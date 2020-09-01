#include <vector>

std::vector<int>::iterator func(std::vector<int>::iterator beg, std::vector<int>::iterator end, int value)
{
    while (beg != end && *beg != value) {
        ++beg;
    }
    return beg;
}