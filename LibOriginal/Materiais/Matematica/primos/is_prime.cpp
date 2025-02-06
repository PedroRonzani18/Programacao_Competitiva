// Descricao: Funcao que verifica se um numero n eh primo.
// Complexidade: O(sqrt(n))
bool isPrime(int n) {
    return n > 1 and lowestPrimeFactor(n) == n;
}
