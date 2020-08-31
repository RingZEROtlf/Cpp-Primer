char *init(int ht, int wd = 80, char bckgrnd = ' ');

int main()
{
    init();
    init(24, 10);
    init(14, '*');
    return 0;
}