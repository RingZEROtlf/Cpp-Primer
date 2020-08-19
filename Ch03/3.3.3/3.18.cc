#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    // wrong
    ivec[0] = 42;

    // right
    ivec.push_back(42);

    return 0;
}