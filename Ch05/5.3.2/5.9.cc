#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    int counter = 0;
    while (cin >> word) {
        for (auto &c: word) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++counter;
            }
        }
    }
    cout << counter << endl;
    return 0;
}