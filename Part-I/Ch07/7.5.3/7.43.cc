class NoDefault
{
public:
    NoDefault(int a);
};

class C
{
public:
    C() : member(0) {}
private:
    NoDefault member;
};