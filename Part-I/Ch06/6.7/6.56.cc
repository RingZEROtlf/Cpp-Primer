#include <iostream>
#include <vector>
using namespace std;

vector<int(int, int)> vec;

int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int main()
{
    vec.push_back(sum);
    vec.push_back(sub);
    vec.push_back(mul);
    vec.push_back(div);

    int a = 7, b = 2;
    cout << vec[0](a, b) << endl;
    cout << vec[1](a, b) << endl;
    cout << vec[2](a, b) << endl;
    cout << vec[3](a, b) << endl;
    return 0;
}