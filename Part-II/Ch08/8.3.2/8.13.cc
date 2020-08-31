#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (const auto &entry: people) {
        ostringstream formatted, badNums;
        for (const auto &nums: entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty()) {
            os << entry.name << " "
               << formatted.str() << endl;
        } else {
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << end;
        }
    }

    return 0;
}