#include "Query.hpp"

int main()
{
    BinaryQuery a = Query("fiery") & Query("bird");
    AndQuery b = Query("firey") & Query("bird");
    OrQuery c = Query("fiery") & Query("bird");
}