#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> func(std::string filename)
{
    std::vector<std::string> vec;
    std::ifstream input(filename);
    if (input) {
        std::string line;
        while (std::getline(input, line)) {
            vec.push_back(line);
        }
    } else {
        std::cerr << "Couldn't open: " << filename << std::endl;
    }
    input.close();
    return vec;
}

int main()
{
    return 0;
}