// Primos - Lowest Prime Factor
// 
// Menor fator primo de n
// O(sqrt(n))

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
