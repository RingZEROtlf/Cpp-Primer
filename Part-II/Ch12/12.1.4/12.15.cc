#include <memory>
using namespace std;

struct destination {};
struct connection {};

connection connect(destination* dest)
{
    return connection();
}

void disconnect(connection conn)
{}

void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p) {
        disconnect(*p);
    });
}

int main()
{
    return 0;
}