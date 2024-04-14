// Description: Retorna o numero de fatores primos de N
// Complexidade: O(log(N))

vi p; // vetor de primos p (sieve(10000000))

int numPF(int N) {
    int ans = 0;
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        while (N%p[i] == 0) { N /= p[i]; ++ans; }
    return ans + (N != 1);
}