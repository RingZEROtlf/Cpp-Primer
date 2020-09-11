#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const&;
private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    std::cout << "Foo Foo::sorted() &&" << std::endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const&
{
    std::cout << "Foo Foo::sorted() const&" << std::endl;
    return Foo(*this).sorted();
}

int main()
{
    Foo foo;
    foo.sorted();
    std::cout << "Finished" << std::endl;
    return 0;
}