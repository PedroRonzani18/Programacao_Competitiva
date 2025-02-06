// Description: Verifica se dois numeros primos somam um numero n.
// Complexity: O(sqrt(n))
bool twoNumsSumPrime(int n) {
    
    if(n % 2 == 0) return true;
    return isPrime(n-2);
}