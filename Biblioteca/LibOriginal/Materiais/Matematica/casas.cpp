// Descriptiuon: Conta quantas casas decimais certo numero tem

int casas(double a) {
    return (int)floor(1 + log10((double)a))
}