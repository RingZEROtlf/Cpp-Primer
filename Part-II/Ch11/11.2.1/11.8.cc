#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void add(vector<string> &vec, const string &word)
{
    if (find(vec.begin(), vec.end(), word) == vec.end()) {
        vec.push_back(word);
    }
}

int main()
{
    vector<string> vec { "1", "2", "321" };
    add(vec, "1");
    add(vec, "5");
    return 0;
}