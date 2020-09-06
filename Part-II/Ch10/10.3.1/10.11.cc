#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
    stable_sort(words.begin(), words.end(), isShorter);
    words.erase(unique(words.begin(), words.end()), words.end());
}

int main()
{
    vector<string> words { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    elimDups(words);
    for (auto &word: words) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}