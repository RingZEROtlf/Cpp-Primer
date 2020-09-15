#ifndef STR_BLOB_HPP
#define STR_BLOB_HPP

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <algorithm>

class StrBlob;
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::vector<std::string>::iterator begin();
    std::vector<std::string>::const_iterator begin() const;
    std::vector<std::string>::iterator end();
    std::vector<std::string>::const_iterator end() const;
    std::string& front() const;
    std::string& back() const;

    auto& operator[](std::size_t n)
    {
        return (*data)[n];
    }

    const auto& operator[](std::size_t n) const
    {
        return (*data)[n];
    }

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob()
    : data(std::make_shared<std::vector<std::string>>())
{}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il))
{}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::vector<std::string>::iterator
StrBlob::begin()
{
    return data->begin();
}

std::vector<std::string>::const_iterator
StrBlob::begin() const
{
    return data->begin();
}

std::vector<std::string>::iterator
StrBlob::end()
{
    return data->end();
}

std::vector<std::string>::const_iterator
StrBlob::end() const
{
    return data->end();
}

std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    } else {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);

public:
    StrBlobPtr()
        : curr(0)
    {}
    
    StrBlobPtr(StrBlob &a, size_t sz = 0)
        : wptr(a.data), curr(sz)
    {}

    std::string& deref() const;
    StrBlobPtr& incr();

    StrBlobPtr& operator++()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

    StrBlobPtr& operator--()
    {
        --curr;
        check(curr, "decrement past begin of StrBlobPtr");
        return *this;
    }

    StrBlobPtr operator++(int)
    {
        StrBlobPtr ret = *this;
        ++*this;
        return ret;
    }

    StrBlobPtr operator--(int)
    {
        StrBlobPtr ret = *this;
        --*this;
        return ret;
    }

    std::string& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    std::string* operator->() const
    {
        return &this->operator*();
    }

private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

// std::string& StrBlobPtr::deref() const
// {
//     return (*check(curr, "derefence past end"))[curr];
// }

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !lhs.wptr.expired() && !rhs.wptr.expired() && lhs.wptr.lock() == rhs.wptr.lock();
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto a = lhs.wptr.expired() ? nullptr : lhs.wptr.lock();
    auto b = rhs.wptr.expired() ? nullptr : rhs.wptr.lock();
    return a < b;
}

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr()
        : curr(0)
    {}
    
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0)
        : wptr(a.data), curr(sz)
    {}

    const std::string& deref() const;
    ConstStrBlobPtr& incr();

    const std::string& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    const std::string* operator->() const
    {
        return &this->operator*();
    }

private:
    std::shared_ptr<const std::vector<std::string>>
        check(std::size_t, const std::string&) const;

    std::weak_ptr<const std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<const std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

const std::string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

#endif