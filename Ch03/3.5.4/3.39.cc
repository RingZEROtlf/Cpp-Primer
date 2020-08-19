#include <iostream>
#include <vector>
#include <cstring>

bool compare_cstring(char *s1, char *s2)
{
    return strcmp(s1, s2) == 0;
}

bool compare_string(std::string s1, std::string s2)
{
    return s1 == s2;
}

int main()
{
    return 0;
}