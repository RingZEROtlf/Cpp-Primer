#include <iostream>

void reset(bool &flag)
{
    flag = false;
}

int main()
{
    bool flag = true;
    reset(flag);
    return 0;
}