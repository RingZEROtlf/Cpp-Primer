#include <list>
#include <vector>
#include <string>
using namespace std;

int main()
{
    list<char*> lst = { "a", "b", "c", "d", "e" };
    vector<string> vec;
    vec.assign(lst.begin(), lst.end());
    return 0;
}