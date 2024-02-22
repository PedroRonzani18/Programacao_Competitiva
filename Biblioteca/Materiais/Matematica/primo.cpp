// Descricao: Funcao que verifica se um numero n eh primo.
// Complexidade: O(sqrt(n))
unsigned lowestPrimeFactor(unsigned n, unsigned startPrime = 2) {
    if (startPrime <= 3) {
        if (not (n & 1))
            return 2;
        if (not (n % 3))
            return 3;
        startPrime = 5;
    }

    for (unsigned i = startPrime; i * i <= n; i += (i + 1) % 6 ? 4 : 2)
        if (not (n % i))
            return i;
    return n;
}

bool isPrime(unsigned n) {
    return n > 1 and lowestPrimeFactor(n) == n;
}
