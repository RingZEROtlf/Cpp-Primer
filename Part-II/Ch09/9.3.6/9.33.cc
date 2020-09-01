#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto begin = vec.begin();
    while (begin != vec.end()) {
        ++begin;
        // begin = vec.insert(begin, 42);
        vec.insert(begin, 42);
        ++begin;
    }
    for (auto &v: vec) {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}