const int MAX_N = 100010;
const int p = 1e9+7; // p is a prime > MAX_N

int mod(int a, int m) {
  return ((a%m) + m) % m;
}

int modPow(int b, int p, int m) {
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);
  ans = mod(ans*ans, m);
  if (p&1) ans = mod(ans*b, m);
  return ans;
}

int inv(int a) { 
    return modPow(a, p-2, p); 
} 

int fact[MAX_N];

int comb(int n, int k) {
    // O(log p)
    if (n < k) return 0;
    // clearly
    return (((fact[n] * inv(fact[k])) % p) * inv(fact[n-k])) % p;
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; ++i)
    fact[i] = (fact[i-1]*i) % p;
    cout << C(100000, 50000) << "\n";
}