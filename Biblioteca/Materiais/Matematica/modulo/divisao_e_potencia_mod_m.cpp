// Retorna a % m (garante que o resultado é positivo)
int mod(int a, int m) {
    return ((a%m) + m) % m;
}

// Description: retorna b^(-1) mod m, ou -1 se não existir.
// Complexidade: O(log(min(b, m)))
int modInverse(int b, int m) {
    int x, y;
    int d = extEuclid(b, m, x, y);
    if (d != 1) return -1;
    return mod(x, m);
}

// Description: retorna b^p mod m
// Complexidade: O(log(p))
int modPow(int b, int p, int m) {
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);
  ans = mod(ans*ans, m);
  if (p&1) ans = mod(ans*b, m);
  return ans;
}