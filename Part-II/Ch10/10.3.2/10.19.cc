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

string make_plural(size_t count, string s, string postfix)
{
    return count > 1 ? s + postfix : s;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &a) {
        return a.size() >= sz;
    });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s) {
        cout << s << " ";
    });
}

int main()
{
    vector<string> words { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    biggies(words, 6);
    for (auto &word: words) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}