#include <iostream>
#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price)
    {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
        { return n * price; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc)
    {}
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class New_quote : public Bulk_quote
{
public:
    New_quote() = default;
    New_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Bulk_quote(book, p, qty, disc)
    {}
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= min_qty)
            return min_qty * price + (cnt - min_qty) * (1 - discount) * price;
        else
            return cnt * price;
    }
};

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main()
{
    Quote quote("quote", 100);
    print_total(std::cout, quote, 5);
    Bulk_quote bulk_quote("bulk_quote", 100, 4, 0.2);
    print_total(std::cout, bulk_quote, 5);
    New_quote new_quote("new_quote", 100, 4, 0.2);
    print_total(std::cout, new_quote, 5);
}