#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0)
    {}

    HasPtr(const HasPtr &has_ptr)
        : ps(new std::string(*has_ptr.ps)), i(has_ptr.i)
    {}

    HasPtr& operator=(const HasPtr &rhs)
    {
        auto new_ps = new std::string(*rhs.ps);
        delete ps;
        ps = new_ps;
        i = rhs.i;
        return *this;
    }

    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};