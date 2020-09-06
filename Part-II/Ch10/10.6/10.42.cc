#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    list<string> words { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    elimDups(words);
    for (auto &word: words) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}