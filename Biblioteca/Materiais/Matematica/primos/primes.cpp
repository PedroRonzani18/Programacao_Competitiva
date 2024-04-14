#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef vector<int> vi;

int _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vi p;                                           // compact list of primes

void sieve(int upperbound) {                      // range = [0..upperbound]
    _sieve_size = upperbound+1;                    // to include upperbound
    bs.set();                                      // aint 1s
    bs[0] = bs[1] = 0;                             // except index 0+1
    for (int i = 2; i < _sieve_size; ++i) if (bs[i]) {
        for (int j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        p.push_back(i);                              // add prime i to the list
    }
}

bool isPrime(int N) {                             // good enough prime test
    if (N < _sieve_size) return bs[N];             // O(1) for small primes
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        if (N%p[i] == 0)
        return false;
    return true;                                   // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

// second part

vi primeFactors(int N) {                         // pre-condition, N >= 1
    vi factors;
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        while (N%p[i] == 0) {                        // found a prime for N
        N /= p[i];                                 // remove it from N
        factors.push_back(p[i]);
        }
    if (N != 1) factors.push_back(N);              // remaining N is a prime
    return factors;
}

// Description: Retorna o numero de fatores primos de N
int numPF(int N) {
    int ans = 0;
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        while (N%p[i] == 0) { N /= p[i]; ++ans; }
    return ans + (N != 1);
}

int numDiffPF(int N) {
    int ans = 0;
    for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
        if (N%p[i] == 0) ++ans;                      // count this prime factor
        while (N%p[i] == 0) N /= p[i];               // only once
    }
    if (N != 1) ++ans;
    return ans;
}

int sumPF(int N) {
    int ans = 0;
    for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i)
        while (N%p[i] == 0) { N /= p[i]; ans += p[i]; }
    if (N != 1) ans += N;
    return ans;
}

// Description: Retorna o numero de divisores de N
// Complexidade: O(log(N))
// Exemplo: numDiv(60) = 12 {1,2,3,4,5,6,10,12,15,20,30,60}
int numDiv(int N) {
    int ans = 1;                                   // start from ans = 1
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
        int power = 0;                               // count the power
        while (N%p[i] == 0) { N /= p[i]; ++power; }
        ans *= power+1;                              // fointow the formula
    }
    return (N != 1) ? 2*ans : ans;                 // last factor = N^1
}


// Description: Retorna a soma dos divisores de N
// Complexidade: O(log(N))
// Exemplo: sumDiv(60) = 168 : 1+2+3+4+5+6+10+12+15+20+30+60
int sumDiv(int N) {
    int ans = 1;
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
        int multiplier = p[i], total = 1;
        while (N%p[i] == 0) {
        N /= p[i];
        total += multiplier;
        multiplier *= p[i];
        }
        ans *= total;
    }
    if (N != 1) ans *= (N+1);
    return ans;
}

int EulerPhi(int N) {
    int ans = N;                                    // start from ans = N
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
        if (N%p[i] == 0) ans -= ans/p[i];            // count unique
        while (N%p[i] == 0) N /= p[i];               // prime factor
    }
    if (N != 1) ans -= ans/N;                      // last factor
    return ans;
}

int32_t main() {
    // first part: the Sieve of Eratosthenes
    sieve(10000000);                               // up to 10^7 (<1s)
    cout << p.back() << "\n";               // primes.back() = 9999991
    for (int i = p.back()+1; ; ++i)
        if (isPrime(i)) {
        cout << "The next prime beyond the last prime generated is " << i << "\n";
        break;
        }
    cout << isPrime((1LL<<31)-1) << "\n";          // 8th Mersenne prime
    cout << isPrime(136117223861LL) << "\n";       // 104729*1299709
    cout << "\n";

    // second part: prime factors
    vi r;

    r = primeFactors((1LL<<31)-1);                 // Mersenne prime
    cout << (1LL<<31)-1 << "\n";
    for (auto &pf : r) cout << "> " << pf << "\n";
    cout << "\n";

    r = primeFactors(136117223861LL);              // large prime factors
    cout << 136117223861LL << "\n";
    for (auto &pf : r) cout << "> " << pf << "\n";     // 104729*1299709
    cout << "\n";

    r = primeFactors(5000000035LL);                // large prime factors
    cout << 5000000035LL << "\n";
    for (auto &pf : r) cout << "> " << pf << "\n";     // 5*1000000007
    cout << "\n";

    r = primeFactors(142391208960LL);              // large composite
    cout << 142391208960LL << "\n";
    for (auto &pf : r) cout << "> " << pf << "\n";     // 2^10*3^4*5*7^4*11*13
    cout << "\n";

    r = primeFactors(100000380000361LL);           // 10000019^2
    cout << 100000380000361LL << "\n";
    for (auto &pf : r) cout << "> " << pf << "\n";     // fail to factor! (why?)
    cout << "\n";

    
    r = primeFactors((1LL<<31)-1);              // slowest, Mersenne prime
    for (auto &pf : r)
        cout << "> " << pf << "\n";
    r = primeFactors(136117223861LL);              // slow, large prime
    for (auto &pf : r)
        cout << "> " << pf << "\n";                        // 104729*1299709
    r = primeFactors(142391208960LL);              // faster, large composite
    for (auto &pf : r)
        cout << "> " << pf << "\n";                        // 2^10*3^4*5*7^4*11*13
    // r = primeFactors(99999820000081LL);            // the limit: 9999991^2
    // for (auto &pf : r)
    //   cout << "> " << pf << "\n";
    // cout << "\n";

    r = primeFactors(9999973LL*9999973LL);         // 9999973^2, the limit
    for (auto &pf : r)
        cout << "> " << pf << "\n";
    cout << "\n";
    // r = primeFactors(9999991LL*9999991LL);         // 9999991^2, first crash
    // for (auto &pf : r)
    //   cout << "> " << pf << "\n";
    // cout << "\n";

    // third part: functions involving prime factors
    cout << "numPF(" << 60 << ") = " << numPF(60) << "\n";   // 2^2 * 3^1 * 5^1 => 4
    cout << "numDiffPF(" << 60 << ") = " << numDiffPF(60) << "\n"; // 2^2 * 3^1 * 5^1 => 3
    cout << "sumPF(" << 60 << ") = " << sumPF(60) << "\n";   // 2^2 * 3^1 * 5^1 => 2 + 2 + 3 + 5 = 12
    cout << "numDiv(" << 60 << ") = " << numDiv(60) << "\n"; // 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60, 12 divisors
    cout << "sumDiv(" << 60 << ") = " << sumDiv(60) << "\n"; // The summation of 12 divisors above is 168
    cout << "EulerPhi(" << 36 << ") = " << EulerPhi(36) << "\n"; // 12 integers < 36 are relatively prime with 36
    cout << "\n";

    // special cases when N is a prime number
    cout << "numPF(" << 7 << ") = " << numPF(7) << "\n";     // 7^1 => 1
    cout << "numDiffPF(" << 7 << ") = " << numDiffPF(7) << "\n"; // 7^1 = 1
    cout << "sumPF(" << 7 << ") = " << sumPF(7) << "\n";     // 7^1 => 7
    cout << "numDiv(" << 7 << ") = " << numDiv(7) << "\n";   // 1 and 7, 2 divisors
    cout << "sumDiv(" << 7 << ") = " << sumDiv(7) << "\n";   // 1 + 7 = 8
    cout << "EulerPhi(" << 7 << ") = " << EulerPhi(7) << "\n"; // 6 integers < 7 are relatively prime with prime number 7

    return 0;
}