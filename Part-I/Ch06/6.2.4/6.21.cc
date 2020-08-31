#include <iostream>

int compare(int value, int *pvalue)
{
    return value > *pvalue ? value : *pvalue;
}

int main()
{
    return 0;
}