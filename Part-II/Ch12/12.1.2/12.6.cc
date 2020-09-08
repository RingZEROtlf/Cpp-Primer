#include <iostream>
#include <vector>
using namespace std;

vector<int>* f1()
{
    vector<int> *p = new vector<int>();
    return p;
}

void f2(vector<int> *p)
{
    int value;
    while (cin >> value) {
        p->push_back(value);
    }
}

void f3(vector<int> *p)
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
    delete p;
    return 0;
}