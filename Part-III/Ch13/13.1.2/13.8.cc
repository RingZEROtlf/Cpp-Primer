#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0)
    {}

    HasPtr(const HasPtr &has_ptr)
        : ps(new std::string(*(has_ptr.ps))), i(has_ptr.i)
    {}

    HasPtr& operator=(const HasPtr &rhs)
    {
        ps = new std::string(*(rhs.ps));
        i = rhs.i;
    }

private:
    std::string *ps;
    int i;
};