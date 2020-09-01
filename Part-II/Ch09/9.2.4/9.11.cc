#include <vector>
using std::vector;

int main()
{
    vector<int> v1;

    vector<int> v2(v1);
    vector<int> v3(v1);

    vector<int> v4 { 1, 2, 3, 4, 5 };
    vector<int> v5 = { 5, 4, 3, 2, 1 };

    vector<int> v6(v4.begin(), v4.end());

    vector<int> v7(10);
    vector<int> v7(10, -1);

    return 0;
}