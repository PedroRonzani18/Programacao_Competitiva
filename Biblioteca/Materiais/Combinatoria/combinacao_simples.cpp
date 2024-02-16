int combinacaoSimples(int p, int n) {
    return fact(n) / (fact(p) * fact(n - p));
}