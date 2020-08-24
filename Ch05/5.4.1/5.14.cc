#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    map<string, int> counter;
    while (cin >> s) {
        counter[s]++;
    }
    for (auto &&[key, value]: counter) {
        cout << key << " " << value << endl;
    }
    return 0;
}