#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    vector<int> vec(ia, ia + sizeof(ia) / sizeof(ia[0]));
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it % 2 == 0) {
            it = vec.erase(it);
        } else {
            ++it;
        }
    }
    for (auto &v: vec) {
        cout << v << " ";
    }
    cout << "\n";

    list<int> lst(ia, ia + sizeof(ia) / sizeof(ia[0]));
    for (auto it = lst.begin(); it != lst.end(); ) {
        if (*it % 2 == 1) {
            it = lst.erase(it);
        } else {
            ++it;
        }
    }
    for (auto &v: lst) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}