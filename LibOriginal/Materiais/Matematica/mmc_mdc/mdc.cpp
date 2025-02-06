// Description: Calcula o mdc de dois numeros inteiros.
// Complexidade: O(logn) onde n eh o maior numero
int mdc(int a, int b) {
    for (int r = a % b; r; a = b, b = r, r = a % b);
    return b;
}