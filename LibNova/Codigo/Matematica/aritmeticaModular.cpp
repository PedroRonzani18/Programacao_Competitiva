// Aritmetica Modular

int add(int a, int b, int mod) { return (a + b) % mod;}
int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
int mul(int a, int b, int mod) { return (a * b) % mod; }

int mul2(int a, int b, int m) {
    int ret = a*b - int((long double)1/m*a*b+0.5)*m;
    return ret < 0 ? ret + m : ret;
}

int fastExp(int a, int b, int mod) {
    int result = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int mod(int a, int m) {
    return ((a%m) + m) % m;
}

// Complexidade: O(log(min(b, m)))
int modInverse(int b, int m) {
    int x, y;
    int d = extEuclid(b, m, x, y);
    if (d != 1) return -1;
    return mod(x, m);
}
