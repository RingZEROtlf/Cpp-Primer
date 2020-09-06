#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    map<string, vector<pair<string, string>>> family;
    family["Gates"].push_back( { "Bill", "1994-03-13" } );
    return 0;
}