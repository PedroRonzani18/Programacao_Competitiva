// Description: Calcula o mdc de dois numeros inteiros.
// Complexidade: O(logn) onde n eh o maior numero
int mdc(int x, int y) {
    return y ? mdc(y, x % y) : abs(x);
}