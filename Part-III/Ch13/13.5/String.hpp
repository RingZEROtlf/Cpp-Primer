#ifndef STRING_HPP
#define STRING_HPP

#include <memory>
#include <cstring>

class String
{
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

private:
    static std::allocator<char> alloc;
    char *head, *tail;
    size_t size;
};

std::allocator<char> String::alloc;

#endif