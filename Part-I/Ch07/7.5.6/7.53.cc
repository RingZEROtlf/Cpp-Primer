#include <iostream>
using namespace std;

class Debug
{
public:
    constexpr Debug(bool b = true)
        : hw(b), io(b), other(b)
    {}
    constexpr Debug(bool h, bool i, bool o)
        : hw(h), io(i), other(o)
    {}

    constexpr bool any() const { return hw || io || other; }

    void set_hw(bool b) { hw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }

private:
    bool hw;        // hardware error, not IO error
    bool io;        // IO error
    bool other;     // other errors
};

int main()
{
    constexpr Debug io_sub(false, true, false);
    if (io_sub.any())
        cerr << "print appropriate error messages" << endl;
    constexpr Debug prod(false);
    if (prod.any())
        cerr << "print an error message" << endl;
}