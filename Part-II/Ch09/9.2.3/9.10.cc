#include <vector>

int main()
{
    std::vector<int> v1;
    const std::vector<int> v2;
    auto it1 = v1.begin(), it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();

    return 0;
}