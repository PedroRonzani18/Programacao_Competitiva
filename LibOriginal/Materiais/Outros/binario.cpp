// Descicao: conversao de decimal para binario
// Complexidade: O(logn) onde n eh o numero decimal
string decimal_to_binary(int dec) {
    string binary = "";
    while (dec > 0) {
        int bit = dec % 2;
        binary = to_string(bit) + binary;
        dec /= 2;
    }
    return binary;
}

// Descicao: conversao de binario para decimal
// Complexidade: O(logn) onde n eh o numero binario
int binary_to_decimal(string binary) {
    int dec = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        int bit = binary[i] - '0';
        dec += bit * pow(2, power);
        power++;
    }
    return dec;
}
