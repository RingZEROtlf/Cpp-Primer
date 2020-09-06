#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    vector<int> vec;
    copy(in, eof, back_inserter(vec));
    sort(vec.begin(), vec.end());
    for (auto &v: vec) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}