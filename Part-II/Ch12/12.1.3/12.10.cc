#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr)
{
    // using ptr
}

int main()
{
    // right
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));
    cout << *p << endl;
    return 0;
}