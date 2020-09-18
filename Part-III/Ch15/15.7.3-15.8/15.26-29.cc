#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price)
    {
        std::cout << "Quote(const std::string&, double)" << std::endl;
    }

    Quote(const Quote &quote)
        : bookNo(quote.bookNo), price(quote.price)
    {
        std::cout << "Quote(const Quote&)" << std::endl;
    }

    Quote& operator=(const Quote &quote)
    {
        std::cout << "Quote& operator=(const Quote&)" << std::endl;
        bookNo = quote.bookNo;
        price = quote.price;
        return *this;
    }

    Quote(Quote &&quote) noexcept
        : bookNo(std::move(quote.bookNo)), price(std::move(quote.price))
    {
        std::cout << "Quote(Quote&&)" << std::endl;
    }

    Quote& operator=(Quote &&quote) noexcept
    {
        std::cout << "Quote& operatoe=(Quote&&)" << std::endl;
        bookNo = std::move(quote.bookNo);
        price = std::move(quote.price);
        return *this;
    }

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
        { return n * price; }

    virtual ~Quote()
    {
        std::cout << "~Quote()" << std::endl;
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
        std::cout << "Bulk_quote(const std::string&, double, std::size_t, double)" << std::endl;
    }

    using Quote::Quote;

    Bulk_quote(const Bulk_quote &bulk_quote)
        : Quote(bulk_quote), quantity(bulk_quote.quantity), discount(bulk_quote.discount)
    {
        std::cout << "Bulk_quote(const Bulk_quote&)" << std::endl;
    }

    Bulk_quote& operator=(const Bulk_quote &bulk_quote)
    {
        Quote::operator=(bulk_quote);
        std::cout << "Bulk_quote& operator=(const Bulk_quote&)" << std::endl;
        quantity = bulk_quote.quantity;
        discount = bulk_quote.discount;
        return *this;
    }

    Bulk_quote(Bulk_quote &&bulk_quote) noexcept
        : Quote(std::move(bulk_quote)), quantity(std::move(bulk_quote.quantity)), discount(std::move(bulk_quote.discount))
    {
        std::cout << "Bulk_quote(Bulk_quote&&)" << std::endl;
    }
    
    Bulk_quote& operator=(Bulk_quote &&bulk_quote) noexcept
    {
        Quote::operator=(std::move(bulk_quote));
        std::cout << "Bulk_quote& operator=(Bulk_quote&&)" << std::endl;
        return *this;
    }

    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

    ~Bulk_quote() override
    {
        std::cout << "~Bulk_quote()" << std::endl;
    }

private:
    std::size_t quantity;
    double discount;
};

int main()
{
    // Quote quote("quote", 100);
    Bulk_quote bulk("bulk", 100);
    Bulk_quote bulk_quote("bulk_quote", 100, 4, 0.2);

    std::vector<Quote> v1;
    double total1 = 0;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(Bulk_quote("bulk_quote", 100, 4, 0.2));
        total1 += v1.back().net_price(5);
    }
    std::cout << total1 << std::endl;

    std::vector<std::shared_ptr<Quote>> v2;
    double total2 = 0;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(std::make_shared<Bulk_quote>("bulk_quote", 100, 4, 0.2));
        total2 += v2.back()->net_price(5);
    }
    std::cout << total2 << std::endl;
}