#include <iostream>

class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);
    operator int() const { return val; }
private:
    std::size_t val;
};

struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();

    LongDouble operator+(const SmallInt&);
};

LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;

int main() {
    ld = si + ld;
    ld = ld + si;
}