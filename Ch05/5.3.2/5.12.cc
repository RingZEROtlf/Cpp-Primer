#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    int counter = 0;
    int blandCnt = 0, tabCnt = 0, newLineCnt = 0;
    while (cin >> word) {
        char prev = ' ';
        for (auto &c: word) {
            if (prev == 'f') {
                switch (c) {
                    case 'f':
                    case 'l':
                    case 'i':
                        ++counter;
                        break;
                    default:
                        break;
                }
            }
            prev = c;
        }
    }
    cout << counter << endl;
    return 0;
}