#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    const int size = 1048;
    vector<string> svec;
    svec.reserve(1024);
    string word;
    for (int i = 0; i < size; ++i) {
        word = "123";
        svec.push_back(word);
    }
    svec.resize(svec.size() + svec.size() / 2);
    cout << svec.capacity() << endl;
    return 0;
}