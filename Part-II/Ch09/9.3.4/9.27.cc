#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> lst { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto prev = lst.before_begin();
    auto curr = lst.begin();
    while (curr != lst.end()) {
        if (*curr % 2 == 1) {
            curr = lst.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }
    return 0;
}