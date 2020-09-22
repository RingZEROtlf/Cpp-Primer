#include <vector>
using std::vector;

vector<int(*)(int, int)> vec;

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
    return 0;
}