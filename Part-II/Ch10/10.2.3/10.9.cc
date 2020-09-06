#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
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