int mdc(int x, int y) {
    return y ? mdc(y, x % y) : abs(x);
}