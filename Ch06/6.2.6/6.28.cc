#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem: il) {
        cout << elem << " ";
    }
    cout << endl;
}