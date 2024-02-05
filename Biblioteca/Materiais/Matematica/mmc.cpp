// Description: Calcula o mmc de dois números inteiros.
// Complexidade: O(logn) onde n eh o maior numero
int mmc(int x, int y) { 
   return (x && y ? (return abs(x) / mdc(x, y) * abs(y)) : abs(x | y));
}
