#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    bool operator<(const HasPtr &rhs) const
    {
        return *ps < *rhs.ps;
    }

    std::string get_string() const
    {
        return *ps;
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

int main()
{
    std::vector<HasPtr> vec;
    vec.emplace_back("3");
    vec.emplace_back("2");
    vec.emplace_back("1");
    std::sort(vec.begin(), vec.end());
    for (auto &v: vec) {
        std::cout << v.get_string() << " ";
    }
    std::cout << std::endl;
    return 0;
}