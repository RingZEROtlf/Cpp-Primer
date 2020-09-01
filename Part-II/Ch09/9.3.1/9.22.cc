#include <vector>
using namespace std;

int main()
{
    int some_val = 5;
    vector<int> iv;
    vector<int>::iterator iter = iv.begin(),
                          mid = iv.begin() + iv.size() / 2;
    while (iter != mid) {
        if (*iter == some_val) {
            iv.insert(iter, 2 * some_val);
        }
    }
    return 0;
}