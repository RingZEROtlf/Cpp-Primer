#ifndef STR_VEC_HPP
#define STR_VEC_HPP

#include <string>
#include <memory>
#include <utility>
#include <algorithm>

class StrVec
{
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);

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
    StrVec& operator=(std::initializer_list<std::string> il)
    {
        auto data = alloc_n_copy(il.begin(), il.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }

    StrVec(StrVec &&s) noexcept
        : elements(s.elements), first_free(s.first_free), cap(s.cap)
    {
        s.elements = s.first_free = s.cap = nullptr;
    }

    StrVec& operator=(StrVec &&rhs) noexcept
    {
        if (this != &rhs) {
            free();
            elements = rhs.elements;
            first_free = rhs.first_free;
            cap = rhs.cap;
            rhs.elements = rhs.first_free = rhs.cap = nullptr;
        }
        return *this;
    }

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

    std::string& operator[](std::size_t n)
    {
        return elements[n];
    }

    const std::string& operator[](std::size_t n) const
    {
        return elements[n];
    }

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
    auto first = alloc.allocate(new_capacity);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
                                        std::make_move_iterator(end()),
                                        first);
    free();
    elements = first;
    first_free = last;
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

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    } else {
        return std::equal(lhs.elements, lhs.first_free, rhs.elements);
    }
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 < lhs.end() && it2 < rhs.end(); ++it1, ++it2) {
        if (*it1 < *it2) {
            return true;
        } else if (*it1 > *it2) {
            return false;
        }
    }
    return it1 == lhs.end();
}

#endif