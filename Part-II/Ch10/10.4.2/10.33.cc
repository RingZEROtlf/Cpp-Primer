#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin(argv[1]);
    istream_iterator<int> in(fin), eof;
    ostream_iterator<int> out1(ofstream(argv[2]), " "), out2(ofstream(argv[3]), "\n");
    vector<int> vec(in, eof);
    for (auto &v: vec) {
        if (v % 2 == 1) {
            out1 = v;
        } else {
            out2 = v;
        }
    }
    return 0;
}