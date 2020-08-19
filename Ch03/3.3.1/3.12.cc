#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<vector<int>> ivec;
    vector<string> svec = ivec;
    vector<string> svec(10, "null");
    return 0;
}