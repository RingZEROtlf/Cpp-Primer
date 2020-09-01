#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 { 1, 2, 3, 4, 5 };
    vector<int> v2 { 1, 2, 3, 5, 4, 6 };
    bool is_equal = (v1.size() == v2.size());
    for (decltype(v1.size()) idx = 0; is_equal && idx < v1.size(); ++idx) {
        is_equal &= (v1[idx] == v2[idx]);
    }
    cout << is_equal << endl;
    return 0;
}