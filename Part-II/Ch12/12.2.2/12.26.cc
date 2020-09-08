#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    constexpr size_t n = 128;
    allocator<string> alloc;
    string *const p = alloc.allocate(n);
    string s;
    string *q = p;
    while (cin >> s && q != p + n) {
        alloc.construct(q, s);
    }
    const size_t size = q - p;
    for (size_t idx = 0; idx < size; ++idx) {
        alloc.destroy(p + idx);
    }
    alloc.deallocate(p, n);
    return 0;
}