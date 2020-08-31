#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string>::iterator iter;
    *iter++;
    (*iter)++;
    *iter.empty();
    iter->empty();
    ++*iter;
    iter++->empty();
    return 0;
}