#include <vector>
using namespace std;

int main()
{
    vector<int> c { 1 };
    if (!c.empty()) {
        auto val = *c.begin(), val2 = c.front();
        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();
    }
    return 0;
}