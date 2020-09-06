#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <set>
using namespace std;

int main()
{
    map<string, size_t> word_count;
    set<string> exclude = { "the", "but", "and", "or", "an", "a" };
    string word;
    while (cin >> word) {
        string w;
        for (auto &c: word) {
            if (isalpha(c)) {
                w.push_back(tolower(c));
            }
        }
        if (exclude.find(w) == exclude.end()) {
            ++word_count[w];
        }
    }
    return 0;
}