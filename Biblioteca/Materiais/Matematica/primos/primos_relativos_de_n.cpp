// Description: Conta o numero de primos relativos de N
// Complexidade: O(log(N))
// Exemplo: countPrimosRelativos(60) = 16 {1,7,11,13,17,19,23,29,31,37,41,43,47,49,53,59}
// Definicao: Dois numeros sao primos relativos se o mdc entre eles eh 1

int countPrimosRelativos(int N) {
    int ans = N;
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
        if (N%p[i] == 0) ans -= ans/p[i];
        while (N%p[i] == 0) N /= p[i];
    }
    if (N != 1) ans -= ans/N;
    return ans;
}