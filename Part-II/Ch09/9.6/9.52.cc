#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<string> tokens { "(", "(", ")", "(", ")", ")" };
    stack<string> stack;
    for (auto &token: tokens) {
        if (token == "(") {
            stack.push(token);
        } else if (token == ")") {
            stack.pop();
        }
    }
    return 0;
}