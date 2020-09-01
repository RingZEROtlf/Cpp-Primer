#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
    list<int> lst { 1, 2, 3, 4, 5 };
    deque<int> dq1, dq2;
    for (auto &value: lst) {
        if (value % 2 == 0) {
            dq1.push_back(value);
        } else {
            dq2.push_back(value);
        }
    }
    return 0;
}