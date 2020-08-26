#include <iostream>
#include <string>

using ret_type = std::string[10];
std::string (&arr)[10];

std::string (&func1())[10];
ret_type &func2();
auto func3() -> std::string(&)[10];
decltype(arr) func4();