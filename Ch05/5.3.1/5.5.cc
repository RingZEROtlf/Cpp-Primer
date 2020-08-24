#include <iostream>
#include <string>
using namespace std;

int main()
{
    int grade = 90;
    string grade_s = "";
    if (grade < 10) {
        grade_s += '0' + grade;
    } else {
        grade_s += '0' + grade / 10;
        grade_s += '0' + grade % 10;
    }
    return 0;
}