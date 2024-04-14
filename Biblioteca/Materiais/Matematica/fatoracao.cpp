// Fatora um número em seus fatores primos
// Complexidade: O(sqrt(n))
// Ex: factorize(1200) = {2: 4, 3: 1, 5: 2}

int lowestPrimeFactor(int n, int startPrime = 2) {
    if (startPrime <= 3) {
        if (not (n & 1)) return 2;
        if (not (n % 3)) return 3;
        startPrime = 5;
    }

    for (int i = startPrime; i * i <= n; i += (i + 1) % 6 ? 4 : 2)
        if (not (n % i))
            return i;
    return n;
}

map<int, int> factorize(int n) {
    map<int, int> factorsOfN;
    int lowestPrimeFactorOfN = 2;

    while (n != 1) {
        lowestPrimeFactorOfN = lowestPrimeFactor(n, lowestPrimeFactorOfN);
        factorsOfN[lowestPrimeFactorOfN] = 1;
        n /= lowestPrimeFactorOfN;
        while (not (n % lowestPrimeFactorOfN)) {
            factorsOfN[lowestPrimeFactorOfN]++;
            n /= lowestPrimeFactorOfN;
        }
    }

    return factorsOfN;
}