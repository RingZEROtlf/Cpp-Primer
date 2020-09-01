#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    Date(const string& s_date) {
        decltype(s_date.size()) prev_pos = 0, pos = 0;
        for (int i = 0; i < 3; ++i) {
            auto beg = s_date.find_first_not_of(seperators, pos);
            auto end = s_date.find_first_of(seperators, beg);
            auto ss = s_date.substr(beg, end - beg);
            if (i == 0) {
                try {
                    month = stoi(ss);
                } catch (exception &e) {
                    month = 0;
                    for (int ii = 1; ii <= 12; ++ii) {
                        if (ss == months[ii] || ss == months_abbr[ii]) {
                            month = ii;
                            break;
                        }
                    }
                }
            } else if (i == 1) {
                day = stoi(ss);
            } else if (i == 2) {
                year = stoi(ss);
            }
            pos = end;
        }
    }

    void print() const {
        cout << "year: " << year << ", month: " << month << ", day: " << day << endl;
    }

private:
    const string months[13] = {
        "", "January", "Febrary", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };
    const string months_abbr[13] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
        "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    const string seperators = " ,/";
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

int main()
{
    Date date("Jan 1, 1990");
    date.print();
    return 0;
}