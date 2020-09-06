#include <iostream>
using namespace std;

int main()
{
    int value = 5;
    auto func = [value]() mutable {
        if (value > 0) {
            --value;
        }
        return value == 0;
    };
    for (int i = 0; i < 10; ++i) {
        cout << func() << endl;
    }
    return 0;
}