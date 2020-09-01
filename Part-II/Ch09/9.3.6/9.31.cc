#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = vi.before_begin();
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2 == 1) {
            iter = vi.insert_after(iter, *iter);
            prev = iter;
            ++iter;
        } else {
            iter = vi.erase_after(prev);
        }
    }
    for (auto &v: vi) {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}