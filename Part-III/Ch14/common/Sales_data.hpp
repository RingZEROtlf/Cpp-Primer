#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
#include <sstream>

class Sales_data
{
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend std::istream &operator>>(std::istream&, Sales_data&);
    friend std::ostream &operator<<(std::ostream&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &s)
        : Sales_data(s, 0, 0)
    {
        std::cout << "construct using `string`" << std::endl;
    }
    Sales_data(const std::string &s, unsigned int n, double p)
        : bookNo(s), units_sold(n), revenue(p*n)
    {
        std::cout << "construct using `string`, `unsigned int`, `double`" << std::endl;
    }
    Sales_data(std::istream & is)
    {
        std::cout << "construct using `istream`" << std::endl;
        is >> *this;
    }

    std::string isbn() const
    {
        return bookNo;
    }

    Sales_data& combine(const Sales_data& other)
    {
        units_sold += other.units_sold;
        revenue += other.revenue;
        return *this;
    }

    inline double avg_price() const
    {
        if (units_sold)
            return revenue / units_sold;
        else
            return 0;
    }

    Sales_data& operator+=(const Sales_data&);

    operator std::string() const
    {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }

    operator double() const
    {
        return avg_price();
    }

private:
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

Sales_data operator+(const Sales_data& d1, const Sales_data& d2)
{
    Sales_data ret(d1);
    ret += d2;
    return ret;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    this->combine(rhs);
    return *this;
}

std::ostream &operator<<(std::ostream& out, const Sales_data& d)
{
    out << d.isbn() << "\t" << d.units_sold << "\t" << d.revenue << "\t" << d.avg_price();
    return out;
}

std::istream &operator>>(std::istream& in, Sales_data& d)
{
    double price;
    in >> d.bookNo >> d.units_sold >> price;
    if (in)
        d.revenue = d.units_sold * price;
    else
        d = Sales_data();
    return in;
}

#endif