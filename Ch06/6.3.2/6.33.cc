#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &vec, vector<int>::iterator it)
{
    if (it == vec.end()) {
        std::cout << "\n";
    } else {
        std::cout << *it << " ";
        print_vector(vec, ++it);
    }
}

int main()
{
    vector<int> vec { 1, 2, 3, 4, 5 };
    print_vector(vec, vec.begin());
    return 0;
}