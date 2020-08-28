#include <iostream>
#include <string>

class Person
{
friend std::istream& operator>>(std::istream&, Person&);
friend std::ostream& operator<<(std::ostream&, const Person&);

public:
    Person() = default;
    Person(const std::string name, const std::string address)
        : name(name), address(address) {}
    explicit Person(std::istream& in) { in >> *this; }

    std::string get_name() const
    {
        return name;
    }

    std::string get_address() const
    {
        return address;
    }

private:
    std::string name = "anonymous";
    std::string address = "none";
};

std::istream& operator>>(std::istream& in, Person& person)
{
    in >> person.name >> person.address;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& person)
{
    out << person.name << "\t" << person.address;
    return out;
}