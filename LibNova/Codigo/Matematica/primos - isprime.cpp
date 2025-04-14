// Primos - IsPrime - Tradicional
//
// Verifica se um numero eh primo
// O(sqrt(n)): 0 <= n <= 10^7 

bool isPrime(int n) {
    return n > 1 and lowestPrimeFactor(n) == n;
}
