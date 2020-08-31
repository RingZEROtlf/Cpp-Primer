#include <iostream>
#include <string>

class Sales_data
{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
    Sales_data(std::string s = "") : bookNo(s) {}
    Sales_data(std::string s, unsigned int n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream & is)
    {
        read(is, *this);
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

private:
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data& d1, const Sales_data& d2)
{
    Sales_data ret(d1);
    ret.combine(d2);
    return ret;
}

std::ostream &print(std::ostream& out, const Sales_data& d)
{
    out << d.isbn() << "\t" << d.units_sold << "\t" << d.revenue << "\t" << d.avg_price();
    return out; 
}

std::istream &read(std::istream& in, Sales_data& d)
{
    double price;
    in >> d.bookNo >> d.units_sold >> price;
    if (in)
        d.revenue = d.units_sold * price;
    else
        d = Sales_data();
    return in;
}

Sales_data first_item(std::cin);

int main()
{
    Sales_data next;
    Sales_data last("9-999-99999-9");
}