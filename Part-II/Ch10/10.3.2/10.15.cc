#include <iostream>
using namespace std;

int main()
{
    int a = 123;
    auto sum = [a](int b) { return a + b; };
    cout << sum(1) << endl;
    return 0;
}