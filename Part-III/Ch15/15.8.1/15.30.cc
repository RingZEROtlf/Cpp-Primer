#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price)
    {
        // std::cout << "Quote(const std::string&, double)" << std::endl;
    }

    Quote(const Quote &quote)
        : bookNo(quote.bookNo), price(quote.price)
    {
        // std::cout << "Quote(const Quote&)" << std::endl;
    }

    Quote& operator=(const Quote &quote)
    {
        // std::cout << "Quote& operator=(const Quote&)" << std::endl;
        bookNo = quote.bookNo;
        price = quote.price;
        return *this;
    }

    Quote(Quote &&quote) noexcept
        : bookNo(std::move(quote.bookNo)), price(std::move(quote.price))
    {
        // std::cout << "Quote(Quote&&)" << std::endl;
    }

    Quote& operator=(Quote &&quote) noexcept
    {
        // std::cout << "Quote& operatoe=(Quote&&)" << std::endl;
        bookNo = std::move(quote.bookNo);
        price = std::move(quote.price);
        return *this;
    }

    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
        { return n * price; }

    virtual ~Quote()
    {
        // std::cout << "~Quote()" << std::endl;
    }
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
        : Quote(book, p), quantity(qty), discount(disc)
    {
        // std::cout << "Bulk_quote(const std::string&, double, std::size_t, double)" << std::endl;
    }

    using Quote::Quote;

    Bulk_quote(const Bulk_quote &bulk_quote)
        : Quote(bulk_quote), quantity(bulk_quote.quantity), discount(bulk_quote.discount)
    {
        // std::cout << "Bulk_quote(const Bulk_quote&)" << std::endl;
    }

    Bulk_quote& operator=(const Bulk_quote &bulk_quote)
    {
        Quote::operator=(bulk_quote);
        // std::cout << "Bulk_quote& operator=(const Bulk_quote&)" << std::endl;
        quantity = bulk_quote.quantity;
        discount = bulk_quote.discount;
        return *this;
    }

    Bulk_quote(Bulk_quote &&bulk_quote) noexcept
        : Quote(std::move(bulk_quote)), quantity(std::move(bulk_quote.quantity)), discount(std::move(bulk_quote.discount))
    {
        // std::cout << "Bulk_quote(Bulk_quote&&)" << std::endl;
    }
    
    Bulk_quote& operator=(Bulk_quote &&bulk_quote) noexcept
    {
        Quote::operator=(std::move(bulk_quote));
        // std::cout << "Bulk_quote& operator=(Bulk_quote&&)" << std::endl;
        return *this;
    }

    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }

    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

    ~Bulk_quote() override
    {
        // std::cout << "~Bulk_quote()" << std::endl;
    }

private:
    std::size_t quantity;
    double discount;
};

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

class Basket
{
public:
    void add_item(const Quote &sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote &&sale) { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }

    double total_receipt(std::ostream &os) const
    {
        double sum = 0.0;
        for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
            sum += print_total(os, **iter, items.count(*iter));
        }
        std::cout << "Total Sale: " << sum << std::endl;
        return sum;
    }

private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
        { return lhs->isbn() < rhs->isbn(); }

    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items { compare };
};

int main()
{
    Basket basket;
    for (int i = 0; i < 10; ++i) {
        basket.add_item(Bulk_quote("bulk_quote", 100, 4, 0.2));
    }
    for (int i = 0; i < 5; ++i) {
        basket.add_item(Quote("quote", 70));
    }
    basket.total_receipt(std::cout);
}