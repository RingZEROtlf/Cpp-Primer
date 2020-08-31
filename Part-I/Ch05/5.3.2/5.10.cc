#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string word;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    while (cin >> word) {
        for (auto &c: word) {
            switch (tolower(c)) {
                case 'a':
                    ++aCnt;
                    break;
                case 'e':
                    ++eCnt;
                    break;
                case 'i':
                    ++iCnt;
                    break;
                case 'o':
                    ++oCnt;
                    break;
                case 'u':
                    ++uCnt;
                    break;
            }
        }
    }
    cout << aCnt << " " << eCnt << " " << iCnt << " " << oCnt << " " << uCnt << endl;
    return 0;
}