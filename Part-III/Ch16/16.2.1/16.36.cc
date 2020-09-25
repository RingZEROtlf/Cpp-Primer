template <typename T> f1(T, T);
template <typename T1, typename T2> f2(T1, T2);

int i = 0, j = 42, *p1 = &i, &p2 = &j;
const int *cp1 = &i, *cp2 = &j;

int main()
{
  f1(p1, p2);
  f2(p1, p2);
  f1(cp1, cp2);
  f2(cp1, cp2);
  f1(p1, cp1);
  f2(p1, cp1);
}