#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    istream_iterator<string> in(fin), eof;
    vector<string> vec;
    copy(in, eof, back_inserter(vec));
    for (auto &v: vec) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}