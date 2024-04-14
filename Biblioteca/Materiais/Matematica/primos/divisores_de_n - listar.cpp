// Description: Retorna o numero de divisores de N
// Complexidade: O(log(N))
// Exemplo: numDiv(60) = 12 {1,2,3,4,5,6,10,12,15,20,30,60}
int numDiv(int N) {
    int ans = 1;
    for (int i = 0; i < p.size() and p[i]*p[i] <= N; ++i) {
        int power = 0;
        while (N%p[i] == 0) { N /= p[i]; ++power; }
        ans *= power+1;
    }
    return (N != 1) ? 2*ans : ans;
}