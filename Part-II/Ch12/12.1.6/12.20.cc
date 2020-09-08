#include <iostream>
#include <fstream>
#include <string>
#include "../common/StrBlob.hpp"
using namespace std;

int main()
{
    string s;
    ifstream fin("input.txt");
    StrBlob blob;
    while (fin >> s) {
        blob.push_back(s);
    }
    StrBlobPtr blob_pointer(blob);
    try {
        while (true) {
            cout << blob_pointer.deref() << endl;
            blob_pointer.incr();
        }
    } catch (exception &e) {
        // do nothing
    }
    return 0;
}