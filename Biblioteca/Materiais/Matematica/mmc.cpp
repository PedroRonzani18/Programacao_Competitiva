// Description: Calcula o mmc de dois números inteiros.
// Complexidade: O(logn) onde n eh o maior numero
unsigned mmc(unsigned a, unsigned b) {
    return a / mdc(a, b) * b;
}
