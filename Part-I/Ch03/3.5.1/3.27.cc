#include <iostream>

unsigned int buf_size = 1024;

int txt_size()
{
    return 10;
}

int main()
{
    int ia[buf_size];
    int ib[4 * 7 - 14];
    int ic[txt_size()];
    char st[11] = "fundamental";
    return 0;
}