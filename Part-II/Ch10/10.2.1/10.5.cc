#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<char*> roster1 { "123", "321" }, roster2 { "123", "321" };
    cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;
    return 0;
}