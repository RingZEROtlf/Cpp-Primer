#ifndef STR_VEC_HPP
#define STR_VEC_HPP

#include <string>
#include <memory>
#include <utility>
#include <algorithm>

class StrVec
{
public:
    typedef size_t size_type;

    StrVec()
        : elements(nullptr), first_free(nullptr), cap(nullptr)
    {}

    StrVec(std::initializer_list<std::string> il)
        : StrVec()
    {
        for (auto &s: il) {
            push_back(s);
        }
    }

    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const
        { return first_free - elements; }
    size_t capacity() const
        { return cap - elements; }
    std::string* begin() const
        { return elements; }
    std::string* end() const
        { return first_free; }

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const std::string&);

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity()) {
            auto new_capacity = size() ? 2 * size() : 1;
            reallocate(new_capacity); 
        }
    }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void reallocate(size_t);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
    if (elements) {
        std::for_each(elements, first_free, [&](std::string &s) {
            alloc.destroy(&s);
        });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto new_data = alloc_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate(size_t new_capacity)
{
    auto new_data = alloc.allocate(new_capacity);
    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

void StrVec::reserve(size_t new_capacity)
{
    if (new_capacity > capacity()) {
        reallocate(new_capacity);
    }
}

void StrVec::resize(size_t count)
{
    resize(count, "");
}

void StrVec::resize(size_t count, const std::string &value)
{
    if (count > capacity()) {
        reallocate(count);
    }
    if (count > size()) {
        std::for_each(first_free, elements + count, [&](std::string &s) {
            alloc.construct(&s, value);
        });
    } else {
        std::for_each(elements + count, first_free, [&](std::string &s) {
            alloc.destroy(&s);
        });
    }
}

#endif