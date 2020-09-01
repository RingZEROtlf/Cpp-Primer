#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vec { "123", "321", "4444" };
    int sum_of_int = 0;
    for (auto &v: vec) {
        sum_of_int += stoi(v);
    }
    cout << sum_of_int << endl;

    vector<string> vec2 { "123.1", "321", "4444" };
    double sum_of_double = 0;
    for (auto &v: vec2) {
        sum_of_double += stod(v);
    }
    cout << sum_of_double << endl;
    return 0;
}