#include <iostream>
#include <fstream>
#include "Query.hpp"

int main()
{
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::ifstream fin("input.txt");
    TextQuery text_query(fin);
    std::cout << "Executing Query for: " << q.rep() << std::endl
              << q.eval(text_query);
    return 0;
}