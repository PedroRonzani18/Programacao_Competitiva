// Converte um decimal para fracao irredutivel
// Complexidade: O(log n)
pair<int, int> toFraction(double n, unsigned p) {
    const int tenP = pow(10, p);
    const int t = (int) (n * tenP);
    const int rMdc = mdc(t, tenP);
    return {t / rMdc, tenP / rMdc};
}