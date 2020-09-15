#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <memory>
#include <cstring>
#include <algorithm>

class String
{
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator<(const String&, const String&);

public:
    String()
        : head(nullptr), tail(nullptr), size(0)
    {}

    String(char *cstr)
    {
        size = strlen(cstr);
        head = alloc.allocate(size);
        tail = head + size;
        for (auto iter = head; iter != tail; ++iter) {
            alloc.construct(iter, cstr[iter - head]);
        }
    }

    String(const String &rhs)
        : head(alloc.allocate(rhs.size)), tail(head + rhs.size), size(rhs.size)
    {
        for (auto iter = head; iter != tail; ++iter) {
            alloc.construct(iter, *(rhs.head + (iter - head)));
        }
    }

    String& operator=(const String &rhs)
    {
        head = alloc.allocate(rhs.size);
        tail = head + rhs.size;
        size = rhs.size;
        for (auto iter = head; iter != tail; ++iter) {
            alloc.construct(iter, *(rhs.head + (iter - head)));
        }
        return *this;
    }

    ~String()
    {
        if (head) {
            for (auto iter = head; iter != tail; ++iter) {
                alloc.destroy(iter);
            }
            alloc.deallocate(head, size);
        }
    }

    char& operator[](std::size_t n)
    {
        return head[n];
    }

    const char& operator[](std::size_t n) const
    {
        return head[n];
    }

private:
    static std::allocator<char> alloc;
    char *head, *tail;
    size_t size;
};

std::allocator<char> String::alloc;

std::ostream& operator<<(std::ostream &os, const String &s)
{
    std::copy(s.head, s.tail, std::ostream_iterator<char>(os));
}

bool operator==(const String &lhs, const String &rhs)
{
    if (lhs.size != rhs.size) {
        return false;
    } else {
        return std::equal(lhs.head, lhs.tail, rhs.head);
    }
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    auto head1 = lhs.head, head2 = rhs.head;
    auto tail1 = lhs.tail, tail2 = rhs.tail;
    for (; head1 < tail1 && head2 < tail2; ++head1, ++head2) {
        if (*head1 < *head2) {
            return true;
        } else if (*head1 > *head2) {
            return false;
        }
    }
    return head1 == tail1;
}

#endif