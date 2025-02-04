int combinacaoComRepeticao(int p, int n) {
    return fact(n + p - 1) / (fact(p) * fact(n - 1));
}

