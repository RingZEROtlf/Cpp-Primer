#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> func(std::string filename)
{
    std::vector<std::string> vec;
    std::ifstream input(filename);
    if (input) {
        std::string word;
        while (input >> word) {
            vec.push_back(word);
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