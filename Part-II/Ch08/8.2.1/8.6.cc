#include <iostream>
#include <fstream>
#include "../../../Part-I/Ch07/common/Sales_data.h"

int main(int argc, char *argv[])
{
    Sales_data total;
    std::ifstream input(argv[1]);
    if (input) {
        if (read(std::cin, total)) {
            Sales_data trans;
            while (read(std::cin, trans)) {
                if (total.isbn() == trans.isbn())
                    total.combine(trans);
                else {
                    print(std::cout, total) << std::endl;
                    total = trans;
                }
            }
            print(std::cout, total) << std::endl;
        } else {
            std::cerr << "No data?!" << std::endl;
            return -1;
        }
    } else {
        std::cerr << "Couldn't open filename: " << argv[1] << std::endl;
    }
    return 0;
}