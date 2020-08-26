#include <iostream>

void parameter(int param)
{
    param++;
    std::cout << "parameter: " << param << std::endl;
}

void local_object()
{
    int local = 0;
    local++;
    std::cout << "local: " << local << std::endl;
}

void local_static_object()
{
    static int local_static = 0;
    local_static++;
    std::cout << "local_static: " << local_static << std::endl;
}

int main()
{
    parameter(0);
    parameter(1234);
    local_object();
    local_object();
    local_static_object();
    local_static_object();
    return 0;
}