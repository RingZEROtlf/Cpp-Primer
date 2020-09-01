#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(25, 0);
    vec.resize(25);

    vec.resize(100);
    vec.resize(10);

    return 0;
}