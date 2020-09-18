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
    virtual void debug() const
    {
        std::cout << bookNo << " " << price << std::endl;
    }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc)
    {}
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Disc_quote(book, p, qty, disc)
    {}
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
    void debug() const override
    {
        std::cout << quantity << " " << discount << std::endl;
    }
};

class New_quote : public Disc_quote
{
public:
    New_quote() = default;
    New_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Disc_quote(book, p, qty, disc)
    {}
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return quantity * price + (cnt - quantity) * (1 - discount) * price;
        else
            return cnt * price;
    }
    void debug() const override
    {
        std::cout << std::endl;
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
    quote.debug();
    Bulk_quote bulk_quote("bulk_quote", 100, 4, 0.2);
    print_total(std::cout, bulk_quote, 5);
    bulk_quote.debug();
    New_quote new_quote("new_quote", 100, 4, 0.2);
    print_total(std::cout, new_quote, 5);
    new_quote.debug();

    Disc_quote disc_quote("disc_quote", 100, 4, 0.3);
}