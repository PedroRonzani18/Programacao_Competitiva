// Converter um decimal (10) para base n [2, 8, 10, 16]
// Complexidade: O(log n)
char charForDigit(int digit) {
    if (digit > 9) return digit + 87;
    return digit + 48;
}

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

// Converter um numero de base [2, 8, 10, 16] para decimal (10)
// Complexidade: O(n)
int intForDigit(char digit) {
    int intDigit = digit - 48;
    if (intDigit > 9) return digit - 87;
    return intDigit;
}

int baseToDecimal(const string& n, int base = 10) {
    int result = 0;
    int basePow =1;
    for (auto it = n.rbegin(); it != n.rend(); ++it, basePow *= base)
        result += intForDigit(*it) * basePow;
    return result;
}