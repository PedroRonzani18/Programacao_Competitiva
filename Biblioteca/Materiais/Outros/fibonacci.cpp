vector<int> memo(MAX, -1);

// Descricao: Funcao que retorna o n-esimo termo da sequencia de Fibonacci utilizando programacao dinamica.
// Complexidade: O(n) onde n eh o termo desejado
int fibPD(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibPD(n - 1) + fibPD(n - 2);
}