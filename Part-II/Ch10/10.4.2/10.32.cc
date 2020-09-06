#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "../../../Part-I/Ch01/common/Sales_item.h"
using namespace std;

bool compareIsbn(const Sales_item &i1, const Sales_item &i2)
{
    return i1.isbn < i2.isbn;
}

int main()
{
    vector<Sales_item> items;
    istream_iterator<Sales_item> in(cin), eof;
    copy(in, eof, back_inserter(items));
    sort(items.begin(), items.end(), compareIsbn);
    auto it_begin = items.begin();
    while (it_begin != items.end()) {
        auto it_end = find_if_not(it_begin, items.end(), [&](const Sales_item &item) {
            it_begin->isbn == item.isbn;
        });
        auto total = accumulate(it_begin, it_end, Sales_item());
        cout << total << endl;
        it_begin = it_end;
    }
    return 0;
}