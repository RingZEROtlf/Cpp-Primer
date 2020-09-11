#include <string>

class Employee
{
public:
    Employee(const std::string name)
        : name(name), id(id_counter++)
    {}

private:
    static size_t id_counter;
    std::string name;
    size_t id;
};

size_t Employee::id_counter = 0;