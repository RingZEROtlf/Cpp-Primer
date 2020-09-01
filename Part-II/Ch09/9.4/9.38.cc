#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    for (int i = 0; i < 1024; ++i) {
        vec.push_back(i);
        cout << vec.size() << " " << vec.capacity() << endl;
    }
    return 0;
}