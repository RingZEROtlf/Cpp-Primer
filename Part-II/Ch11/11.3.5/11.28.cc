#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<string, vector<int>> mmap { { "123", vector<int>{ 1, 2, 3 } } };
    auto it_find = mmap.find("123");
    return 0;
}