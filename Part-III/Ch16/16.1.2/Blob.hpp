#ifndef BLOB_HPP
#define BLOB_HPP

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
    bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob()
        : data(std::make_shared<std::vector<T>>()) {}
    Blob(std::initializer_list<T> il)
        : data(std::make_shared<std::vector<T>>(il)) {}
    template <typename InputIt>
    Blob(InputIt first, InputIt last)
        : data(std::make_shared<std::vector<T>>(first, last)) {}

    size_type size() const
    {
        return data->size();
    }

    bool empty() const
    {
        return data->empty();
    }

    void push_back(const T &t)
    {
        data->push_back(t);
    }

    void push_back(T &&t)
    {
        data->push_back(std::move(t));
    }

    void pop_back()
    {
        check(0, "pop_back on empty Blob");
        data->pop_back();
    }

    std::vector<T>::iterator begin()
    {
        return data->begin();
    }

    std::vector<T>::const_iterator begin() const
    {
        return data->begin();
    }

    std::vector<T>::iterator end()
    {
        return data->end();
    }

    std::vector<T>::const_iterator end() const
    {
        return data->end();
    }

    T& front()
    {
        check(0, "front on empty Blob");
        return data->front();
    }

    const T& front() const
    {
        check(0, "front on empty Blob");
        return data->front();
    }

    T& back()
    {
        check(0, "back on empty Blob");
        return data->back();
    }

    const T& back() const
    {
        check(0, "back on empty Blob");
        return data->back();
    }

    T& operator[](size_type i)
    {
        check(i, "subscript out of range");
        return (*data)[i];
    }

    const T& operator[](size_type i) const
    {
        check(i, "subscript out of range");
        return (*data)[i];
    }

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const
    {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    else
        return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
class BlobPtr
{
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0)
        : wptr(a.data), curr(sz) {}

    BlobPtr& operator++()
    {
        check(curr, "increment past end of BlobPtr");
        ++curr;
        return *this;
    }

    BlobPtr& operator--()
    {
        --curr;
        check(curr, "decrement past begin of BlobPtr");
        return *this;
    }

    BlobPtr operator++(int)
    {
        BlobPtr ret = *this;
        ++*this;
        return ret;
    }

    BlobPtr operator--(int)
    {
        BlobPtr ret = *this;
        --*this;
        return ret;
    }

    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    T* operator->() const
    {
        return &this->operaotr*();
    }

private:
    std::shared_ptr<std::vector<T>>
    check(std::size_t, const std::string&) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound BlobPtr");
        if (i >= ret->size())
            throw std::out_of_range(msg);
        return ret;
    }

    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

#endif