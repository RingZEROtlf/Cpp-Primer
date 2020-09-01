#include <iostream>
#include <vector>
using namespace std;

int main()
{
    {
        vector<int> vec { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        auto elem1 = vec.begin() + 2, elem2 = vec.begin() + 2;
        elem1 = vec.erase(elem1, elem2);
        for (auto &v: vec) {
            cout << v << " ";
        }
        cout << "\n";
    }
    {
        vector<int> vec { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        auto elem1 = vec.end(), elem2 = vec.end();
        elem1 = vec.erase(elem1, elem2);
        for (auto &v: vec) {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}