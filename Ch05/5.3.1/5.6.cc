#include <iostream>
#include <string>
using namespace std;

int main()
{
    int grade = 90;
    string grade_s = "";
    grade_s += (grade < 10 ? '0' + grade : '0' + grade / 10);
    grade_s += (grade >= 10 ? string(1, '0' + grade % 10) : "");
    return 0;
}