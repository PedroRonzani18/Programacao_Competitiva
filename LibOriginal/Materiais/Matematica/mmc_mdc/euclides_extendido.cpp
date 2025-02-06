// Description: Retorna mdc(a, b) e referencia inteiros x, y t.q ax + by = mdc(a, b).
// Complexidade: O(log(min(a, b)))

int extEuclid(int a, int b, int &x, int &y) {
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a/b;
        tie(a, b) = tuple(b, a%b);
        tie(x, xx) = tuple(xx, x-q*xx);
        tie(y, yy) = tuple(yy, y-q*yy);
    }
    return a;
}