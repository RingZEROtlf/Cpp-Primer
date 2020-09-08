#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> f1()
{
    auto p = make_shared<vector<int>>();
    return p;
}

void f2(shared_ptr<vector<int>> p)
{
    int value;
    while (cin >> value) {
        p->push_back(value);
    }
}

void f3(shared_ptr<vector<int>> p)
{
    for (auto &v: *p) {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    auto p = f1();
    f2(p);
    f3(p);
    return 0;
}