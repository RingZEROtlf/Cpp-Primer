#include "../common/StrBlob.hpp"

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = { "a", "an", "the" };
        b1 = b2;
        b2.push_back("about");
    }

    return 0;
}