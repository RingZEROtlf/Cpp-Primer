template <typename T> void g(T&& val);
template <typename T> void g2(const T& val);
int i = 0; const int ci = i;

int main()
{
  g(i);
  g(ci);
  g(i * ci);

  g(i = ci);

  g2(i);
  g2(ci);
  g2(i * ci);
}