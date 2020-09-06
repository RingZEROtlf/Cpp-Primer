#include "../../../Part-I/Ch07/common/Sales_data.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<Sales_data> vec;
    sort(vec.begin(), vec.end(), [](const Sales_data &d1, const Sales_data &d2) {
        return d1.isbn() < d2.isbn();
    });
    return 0;
}