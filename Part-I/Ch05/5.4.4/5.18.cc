#include <iostream>
using namespace std;

void a()
{
    do
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin);
}

int get_response()
{
    return 42;
}

void b()
{
    do {
        // ...
    } while  (int ival = get_response());
}

void c()
{
    do {
        int ival = get_response();
    } while (ival);
}

int main()
{
    return 0;
}