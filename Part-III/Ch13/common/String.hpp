#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
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
        std::cout << "String(const String&)" << std::endl;
        for (auto iter = head; iter != tail; ++iter) {
            alloc.construct(iter, *(rhs.head + (iter - head)));
        }
    }

    String& operator=(const String &rhs)
    {
        std::cout << "String& operator=(const String&)" << std::endl;
        head = alloc.allocate(rhs.size);
        tail = head + rhs.size;
        size = rhs.size;
        for (auto iter = head; iter != tail; ++iter) {
            alloc.construct(iter, *(rhs.head + (iter - head)));
        }
        return *this;
    }

    String(String &&rhs) noexcept
        : head(rhs.head), tail(rhs.tail), size(rhs.size)
    {
        std::cout << "String(String&&)" << std::endl;
        rhs.head = rhs.tail = nullptr;
        rhs.size = 0;
    }

    String& operator=(String &&rhs) noexcept
    {
        std::cout << "String& operator=(String&&)" << std::endl;
        if (this != &rhs) {
            head = rhs.head;
            tail = rhs.tail;
            size = rhs.size;
            rhs.head = rhs.tail = nullptr;
            rhs.size = 0;
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