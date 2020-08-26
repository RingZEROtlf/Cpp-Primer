void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main()
{
    f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}