#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    using map_t = map<int, vector<int>>;
    using mapped_type_t = map_t::mapped_type;
    using key_type_t = map_t::key_type;
    using value_type_t = map_t::value_type;
    return 0;
}