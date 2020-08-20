#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> grades;
    for (auto &grade: grades) {
        cout << (grade > 90 ? "high pass"
               : grade > 75 ? "pass"
               : grade > 60 ? "low pass" : "fail")
             << endl;
    }
    for (auto &grade: grades) {
        if (grade > 90) {
            cout << "high pass\n";
        } else if (grade > 75) {
            cout << "pass\n";
        } else if (grade > 60) {
            cout << "low pass\n";
        } else {
            cout << "fail\n";
        }
    }
    return 0;
}