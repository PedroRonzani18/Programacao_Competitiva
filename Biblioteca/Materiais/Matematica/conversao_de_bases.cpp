// Converter um decimal (10) para base n [2, 8, 10, 16]
// Complexidade: O(log n)
char charForDigit(uint16_t digit) {
    if (digit > 9) return digit + 87;
    return digit + 48;
}

string decimalToBase(unsigned n, unsigned base = 10) {
    if (not n) return "0";
    stringstream ss;
    for (unsigned i = n; i > 0; i /= base) {
        ss << charForDigit(i % base);
    }
    string s = ss.str();
    reverse(s.begin(), s.end());
    return s;
}

// Converter um numero de base [2, 8, 10, 16] para decimal (10)
// Complexidade: O(n)
uint16_t intForDigit(char digit) {
    uint16_t intDigit = digit - 48;
    if (intDigit > 9) return digit - 87;
    return intDigit;
}

int baseToDecimal(const string& n, unsigned base = 10) {
    int result = 0;
    uint64_t basePow =1;
    for (auto it = n.rbegin(); it != n.rend(); ++it, basePow *= base)
        result += intForDigit(*it) * basePow;
    return result;
}