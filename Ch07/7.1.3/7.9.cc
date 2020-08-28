#include <iostream>
#include <string>

struct Person
{
    std::string get_name() const
    {
        return name;
    }

    std::string get_address() const
    {
        return address;
    }

    std::string name;
    std::string address;
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