#include <iostream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << v1.size() << endl;
    cout << v7.size() << endl;
    for (auto it = v7.begin(); it != v7.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}