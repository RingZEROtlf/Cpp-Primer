#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

void func(forward_list<string> &lst, const string &to_search, const string &to_insert)
{
    auto prev = lst.before_begin();
    auto curr = lst.begin();
    while (curr != lst.end()) {
        if (*curr == to_search) {
            lst.insert_after(curr, to_insert);
            return;
        } else {
            prev = curr;
            ++curr;
        }
    }
    lst.insert_after(prev, to_insert);
}

int main()
{
    return 0;
}