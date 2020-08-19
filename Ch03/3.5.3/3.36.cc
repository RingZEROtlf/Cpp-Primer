#include <iostream>
#include <vector>

bool compare_arrays(int *a1, int *a2, size_t s1, size_t s2)
{
    if (s1 != s2) return false;
    for (size_t i = 0; i < s1; i++) {
        if (a1[i] != a2[i]) return false;
    }
    return true;
}

bool compare_vectors(std::vector<int> v1, std::vector<int> v2)
{
    return v1 == v2;
}

int main()
{
    return 0;
}