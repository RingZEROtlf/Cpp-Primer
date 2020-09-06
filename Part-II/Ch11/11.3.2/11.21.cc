#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count.insert( { word, 0 } ).first->second;
    return 0;
}