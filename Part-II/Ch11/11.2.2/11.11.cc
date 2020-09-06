#include <iostream>
#include <set>
#include "../../../Part-I/Ch01/common/Sales_item.h"
using namespace std;

bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.isbn < rhs.isbn;
}

int main()
{
    multiset<Sales_item, bool(const Sales_item&, const Sales_item&)>
        bookstore(compareIsbn);
    return 0;
}