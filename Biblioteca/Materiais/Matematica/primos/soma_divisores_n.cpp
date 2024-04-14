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