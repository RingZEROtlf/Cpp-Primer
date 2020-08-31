#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(10);
    for (int i = 0; i < 10; i++) {
        vec[i] = i;
    }
    vector<int> vec2 = vec;
    return 0;
}