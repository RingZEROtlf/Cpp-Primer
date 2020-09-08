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

void end_connection(connection *p)
{
    disconnect(*p);
}

void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
}

int main()
{
    return 0;
}