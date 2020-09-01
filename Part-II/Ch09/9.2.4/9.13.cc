#include <list>
#include <vector>
using namespace std;

int main()
{
    list<int> lst = { 1, 2, 3, 4, 5 };
    vector<double> v1(lst.begin(), lst.end());
    vector<int> v2 = { 5, 4, 3, 2, 1 };
    vector<double> v3(v2.begin(), v2.end());
    return 0;
}