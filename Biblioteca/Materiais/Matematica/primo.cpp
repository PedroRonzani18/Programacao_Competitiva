// Descricao: Funcao que verifica se um numero n eh primo.
// Complexidade: O(sqrt(n))
bool prime(int a) {
    if (a == 1)
        return false;
    int lim = round(sqrt(a));
    for (int i = 2; i <= lim; ++i)
        if (a % i == 0)
            return false;
    return true;
}
