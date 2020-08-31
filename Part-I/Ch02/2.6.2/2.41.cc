#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
    double avg_price = 0.0;
};

// 1.20
void ch1_p20()
{
    Sales_data data;
    double price;
    while (std::cin >> data.bookNo >> data.units_sold >> price) {
        data.revenue = data.units_sold * price;
    }
}

// 1.21
void ch1_p21()
{
    Sales_data data1, data2;
    double price1, price2;
    std::cin >> data1.bookNo >> data1.units_sold >> price1
             >> data2.bookNo >> data2.units_sold >> price2;
    data1.revenue = data1.units_sold * price1;
    data2.revenue = data2.units_sold * price2;

    Sales_data data_total {
        data1.bookNo, 
        data1.units_sold + data2.units_sold, 
        data1.revenue + data2.revenue
    };
    std::cout << data_total.bookNo << '\t' 
              << data_total.units_sold << '\t'
              << data_total.revenue << '\t';
    if (data_total.units_sold) {
        std::cout << data_total.revenue / data_total.units_sold << '\n';
    } else {
        std::cout << "0\n";
    }
}

// 1.22
void ch1_p22()
{
    Sales_data data, total;
    double price;
    while (std::cin >> data.bookNo >> data.units_sold >> price) {
        data.revenue = data.units_sold * price;
        total.bookNo = data.bookNo;
        total.units_sold = data.units_sold;
        total.revenue = data.revenue;
    }
    std::cout << total.bookNo << '\t' 
              << total.units_sold << '\t'
              << total.revenue << '\t';
    if (total.units_sold) {
        std::cout << total.revenue / total.units_sold << '\n';
    } else {
        std::cout << "0\n";
    }
}

// 1.23
void ch1_p23()
{

}

// 1.25
void ch1_p25()
{
    
}

int main()
{
    return 0;
}