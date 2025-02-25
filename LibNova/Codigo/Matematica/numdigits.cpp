// Numero de Digitos
//
// Calcula o numero de digitos de n 
// 1234 = 4; 0 = 1

int numDigits(int n) {
    if (n == 0) return 1;
    n = std::abs(n);
    return static_cast<int>(std::floor(std::log10(n))) + 1;
}
