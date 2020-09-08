#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr)
{
    // using ptr
}

int main()
{
    auto p = new int();
    auto sp = make_shared<int>();

    process(sp);
    process(new int());
    process(p);
    process(shared_ptr<int>(p));

    return 0;
}