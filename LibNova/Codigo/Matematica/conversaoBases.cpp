// Conversao de Bases
//
// Converte de 10 -> {2, 8, 10, 16} (log n)
// Converte de {2, 8, 10, 16} -> 10 (n)
char charForDigit(int digit) {
    if (digit > 9) return digit + 87;
    return digit + 48;
}

// 10 -> {2, 8, 10, 16}
string decimalToBase(int n, int base = 10) {
    if (not n) return "0";
    stringstream ss;
    for (int i = n; i > 0; i /= base) {
        ss << charForDigit(i % base);
    }
    string s = ss.str();
    reverse(s.begin(), s.end());
    return s;
}

int intForDigit(char digit) {
    int intDigit = digit - 48;
    if (intDigit > 9) return digit - 87;
    return intDigit;
}

// {2, 8, 10, 16} -> 10
int baseToDecimal(const string& n, int base = 10) {
    int result = 0;
    int basePow =1;
    for (auto it = n.rbegin(); it != n.rend(); ++it, basePow *= base)
        result += intForDigit(*it) * basePow;
    return result;
}
