#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    vector<int> vec, vec2;
    copy(in, eof, back_inserter(vec));
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(vec2));
    for (auto &v: vec2) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}