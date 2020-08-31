#include <iostream>

void a()
{
    int* ip, i, &r = i;
}

void b()
{
    int i, *ip = 0;
}

void c()
{
    int* ip, ip2;
}

int main()
{
    return 0;
}