struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};

void calc(int);
void calc(LongDouble);
double dval;
calc(dval);