class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);
    operator int() const { return val; }
private:
    std::size_t val;
};

int main()
{
    SmallInt s1;
    double d = s1 + 3.14;
}