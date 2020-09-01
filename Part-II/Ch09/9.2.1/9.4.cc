#include <vector>

bool func(std::vector<int>::iterator beg, std::vector<int>::iterator end, int value)
{
    while (beg != end && *beg != value) {
        ++beg;
    }
    return beg != end;
}