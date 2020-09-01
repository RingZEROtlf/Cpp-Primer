#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string ascender = "bdfhijklt", descender = "gjpqy";
    ifstream fin(argv[1]);
    string word, longest = "";
    while (fin >> word) {
        if (word.find_first_of(ascender) != string::npos || word.find_first_of(descender) != string::npos) {
            continue;
        }
        if (longest.size() < word.size()) {
            longest = word;
        }
    }
    cout << longest << endl;
    return 0;
}