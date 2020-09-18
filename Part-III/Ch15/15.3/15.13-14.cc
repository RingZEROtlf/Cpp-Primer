#include <iostream>
#include <string>
using namespace std;

class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename << endl; }
private:
    string basename = "basename";
};

class derived : public base {
public:
    void print(ostream &os) { base::print(os); os << " " << i << endl; }
private:
    int i = 0;
};

int main()
{
    // base b;
    // b.print(cout);
    // derived d;
    // d.print(cout);

    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;

    bobj.print(cout);
    dobj.print(cout);
    cout << bp1->name() << endl;
    cout << bp2->name() << endl;
    br1.print(cout);
    br2.print(cout);
}