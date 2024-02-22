// Description: Calcula o mdc de dois numeros inteiros.
// Complexidade: O(logn) onde n eh o maior numero
unsigned mdc(unsigned a, unsigned b) {
    for (unsigned r = a % b; r; a = b, b = r, r = a % b);
    return b;
}