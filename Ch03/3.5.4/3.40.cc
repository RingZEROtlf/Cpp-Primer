#include <iostream>
#include <cstring>

int main()
{
    char s1[5] = "123", s2[5] = "4321";
    char s3[10];
    strcpy(s3, s1);
    strcat(s3, s2);
    return 0;
}