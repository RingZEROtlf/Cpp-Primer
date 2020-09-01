#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vec;
    auto iter = vec.begin();
    string word;
    while (cin >> word) {
        iter = vec.insert(iter, word);
    }
    return 0;
}