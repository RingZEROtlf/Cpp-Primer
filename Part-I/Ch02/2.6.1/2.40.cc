#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
    double avg_price = 0.0;
};