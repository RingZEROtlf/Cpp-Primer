#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> words { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    cout << count_if(words.begin(), words.end(), [](const string &s) {
        return s.length() > 6;
    }) << endl;
    return 0;
}