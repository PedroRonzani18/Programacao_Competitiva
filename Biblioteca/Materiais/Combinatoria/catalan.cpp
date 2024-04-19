const int MAX_N = 100010;
const int p = 1e9+7; // p is a prime > MAX_N


int mod(int a, int m) {
  return ((a%m) + m) % m;
}

int inv(int a) { 
    return modPow(a, p-2, p); 
} 

int modPow(int b, int p, int m) {
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);
  ans = mod(ans*ans, m);
  if (p&1) ans = mod(ans*b, m);
  return ans;
}

int Cat[MAX_N];

void solve() {
    Cat[0] = 1;
    for (int n = 0; n < MAX_N-1; ++n)              // O(MAX_N * log p)
        Cat[n+1] = ((4*n+2)%p * Cat[n]%p * inv(n+2)) % p;
    cout << Cat[100000] << "\n";                   // the answer is 945729344
}