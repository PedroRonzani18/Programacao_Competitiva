// Description: Retorna o numero de fatores primos diferentes de N
// Complexidade: O(sqrt(N))
// Exemplo: numDiffPF(60) = 3 {2, 3, 5}

int numDiffPF(int N) {
    int ans = 0;
    for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
        if (N%p[i] == 0) ++ans;                      // count this prime factor
        while (N%p[i] == 0) N /= p[i];               // only once
    }
    if (N != 1) ++ans;
    return ans;
}