#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i; double d; const string *ps; char *pc; void *pv;
    
    // (a) pv = (void*) ps;
    pv = reinterpret_cast<void*>(const_cast<string*>(ps));

    // (b) i = int(*pc);
    i = static_cast<int>(*pc);

    // (c) pv = &d;
    pv = reinterpret_cast<void*>(&d);

    // (d) pc = (char*) pv;
    pc = static_cast<char*>(pv);

    return 0;
}