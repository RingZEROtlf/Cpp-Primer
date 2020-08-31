#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> text { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2;
    int sought = 4;
    while (mid != end && *mid != sought) {
        if (sought < *mid) {
            end = mid;
        } else {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }
    return 0;
}