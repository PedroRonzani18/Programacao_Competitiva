// Primos - Primo
// 
// Verifica se um numero eh primo
// O(sqrt(n))
bool isPrime(int n) {
    return n > 1 and lowestPrimeFactor(n) == n;
}
