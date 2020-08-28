struct X {
    X (int i, int j) : base(i), rem(base % j) {}
    int rem, base;
};