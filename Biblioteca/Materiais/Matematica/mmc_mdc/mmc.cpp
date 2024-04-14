// Description: Calcula o mmc de dois números inteiros.
// Complexidade: O(logn) onde n eh o maior numero
int mmc(int a, int b) {
    return a / mdc(a, b) * b;
}
