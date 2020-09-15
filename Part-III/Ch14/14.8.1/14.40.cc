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

struct IsLarger
{
    std::size_t size;
    IsLarger(std::size_t size) : size(size) {}
    bool operator()(const string &s) {
        return s.length() >= size;
    }
};

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    IsLarger il(sz);
    auto wc = find_if(words.begin(), words.end(), il);
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
    elimDups(words);
    for (auto &word: words) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}