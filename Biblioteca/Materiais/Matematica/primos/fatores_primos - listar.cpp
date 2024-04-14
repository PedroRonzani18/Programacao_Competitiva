// Fatora um número em seus fatores primos
// Complexidade: O(sqrt(n))
// Ex: factorize(1200) = {2: 4, 3: 1, 5: 2}

map<int, int> factorize(int n) {
    map<int, int> factorsOfN;
    int lpf = 2;

    while (n != 1) {
        lpf = lowestPrimeFactor(n, lpf);
        factorsOfN[lpf] = 1;
        n /= lpf;
        while (not (n % lpf)) {
            factorsOfN[lpf]++;
            n /= lpf;
        }
    }

    return factorsOfN;
}