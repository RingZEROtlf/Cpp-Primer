#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;

int main()
{
    map<string, function<int(int, int)>> binary_ops = {
        { "+", std::plus<int>() },
        { "-", std::minus<int>() },
        { "*", std::multiplies<int>() },
        { "/", std::divides<int>() },
        { "%", std::modulus<int>() }
    };
    return 0;
}