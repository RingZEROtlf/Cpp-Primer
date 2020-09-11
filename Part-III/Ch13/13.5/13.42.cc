#include <fstream>
#include "TextQuery.hpp"

int main()
{
    std::ifstream fin("input.txt");
    runQueries(fin);
    return 0;
}