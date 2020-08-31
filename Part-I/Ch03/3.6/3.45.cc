#include <iostream>

int main()
{
    int ia[3][4] = {
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 }
    };

    for (auto &row: ia) {
        for (auto col: row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << ia[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for (auto *i = ia; i != ia + 3; i++) {
        for (auto *j = *i; j != *i + 4; j++) {
            std::cout << *j << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}