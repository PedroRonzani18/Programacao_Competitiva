// Description: Encontra o tamanho do ciclo de uma função f(x) = (Z*x + I) % M a partir de um valor inicial L.
// Complexidade: O(lambda + mu) | lambda = tamanho do ciclo | mu = tamanho do prefixo antes do ciclo.
// Return: pair<int, int> = {mu, lambda} | mu = tamanho do prefixo antes do ciclo | lambda = tamanho do ciclo.
// Parameters: x0 = valor inicial para encontrar o ciclo.
int f(int x); // f(x) do problema

pii floydCycleFinding(int x0) {
    int t = f(x0), h = f(f(x0)); 
    while (t != h) { t = f(t); h = f(f(h)); }
    int mu = 0; h = x0;
    while (t != h) { t = f(t); h = f(h); ++mu; }
    int lambda = 1; h = f(t);
    while (t != h) { h = f(h); ++lambda; }
    return {mu, lambda};
}