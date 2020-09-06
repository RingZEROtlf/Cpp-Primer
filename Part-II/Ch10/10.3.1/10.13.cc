#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check(const string &s)
{
    return s.length() >= 5;
}

int main()
{
    vector<string> vec { "1", "12345", "321", "12345678" };
    auto partition_end = partition(vec.begin(), vec.end(), check);
    for (auto it = vec.begin(); it < partition_end; ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}