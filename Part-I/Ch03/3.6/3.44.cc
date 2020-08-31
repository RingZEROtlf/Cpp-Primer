#include <iostream>

int main()
{
    int ia[3][4] = {
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 }
    };

    using row_type = int[4];
    using col_type = int;

    for (row_type &row: ia) {
        for (col_type col: row) {
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

    for (row_type *i = ia; i != ia + 3; i++) {
        for (col_type *j = *i; j != *i + 4; j++) {
            std::cout << *j << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}