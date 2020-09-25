#include <string>
using std::string;

template <typename T> class Stack {};
void f1(Stack<char>);
class Exercise {
    Stack<double> &rsd;
    Stack<int> si;
};
int main() {
    Stack<char> *sc;
    f1(*sc);
    int iOjb = sizeof(Stack<string>);
}