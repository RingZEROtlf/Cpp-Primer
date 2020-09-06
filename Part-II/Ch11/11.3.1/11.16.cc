#include <map>
using namespace std;

int main()
{
    map<int, int> mmap { { 1, 3 } };
    auto map_it= mmap.begin();
    map_it->second = 13;
    return 0;
}