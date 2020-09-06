#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    multimap<string, vector<string>> family;
    family.insert( { "Gates", vector<string>{"Bill", "Hello"} } );
    return 0;
}