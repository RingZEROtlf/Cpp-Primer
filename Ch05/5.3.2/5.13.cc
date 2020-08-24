#include <iostream>
#include <vector>
using namespace std;

char next_text()
{
    return 'c';
}

void a()
{
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
}

unsigned int some_value()
{
    return 42;
}

int get_value()
{
    return 123;
}

void b()
{
    vector<int> ivec;
    unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ix] = index;
            break;
        default:
            ix = ivec.size() - 1;
            ivec[ix] = index;
    }
}

int get_num()
{
    return 321;
}

void c()
{
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddCnt++;
            break;
        case 2, 4, 6, 8, 10:
            evenCnt++;
            break;
    }
}

unsigned int get_bufCnt()
{
    return 4321;
}

void d()
{
    unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch (swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
}

int main()
{
    return 0;
}