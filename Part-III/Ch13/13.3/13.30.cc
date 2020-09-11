#include <string>

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);

public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0)
    {}

    HasPtr(const HasPtr &has_ptr)
        : ps(new std::string(*has_ptr.ps)), i(has_ptr.i)
    {}

    HasPtr& operator=(HasPtr rhs)
    {
        swap(*this, rhs);
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}