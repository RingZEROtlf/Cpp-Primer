#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prefix(vector<int> &v1, vector<int> &v2)
{
    if (v1.size() > v2.size()) {
        swap(v1, v2);
    }
    for (decltype(v1.size()) idx = 0; idx < v1.size(); ++idx) {
        if (v1[idx] != v2[idx]) {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> vec1 { 0, 1, 1, 2 };
    vector<int> vec2 { 0, 1, 1, 2, 3, 5, 8 };

    cout << is_prefix(vec1, vec2) << endl;

    return 0;
}