#include <iostream>
using namespace std;

void a()
{
    int ival1, ival2;
    if (ival1 != ival2)
        ival1 = ival2
}

void b()
{
    int ival, minval, occurs;
    if (ival < minval)
        minval = ival;
        occurs = 1;
}

int get_value()
{
    return 123;
}

void c()
{
    if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
}

void d()
{
    int ival;
    if (ival = 0)
        ival = get_value();
}

int main()
{
    return 0;
}