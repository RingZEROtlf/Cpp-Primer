#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
using namespace std;

int main()
{
    auto print = [](deque<int> vec) {
        for (auto &v: vec) {
            cout << v << " ";
        }
        cout << endl;
    };
    vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    deque<int> v1, v2, v3;
    copy(vec.begin(), vec.end(), inserter(v1, v1.end()));
    print(v1);
    copy(vec.begin(), vec.end(), back_inserter(v2));
    print(v2);
    copy(vec.begin(), vec.end(), front_inserter(v3));
    print(v3);
    return 0;
}