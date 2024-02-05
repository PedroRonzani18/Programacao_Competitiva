char num_to_char(int num) { // 0 -> '0'
    return num + '0';
}

int char_to_num(char c) { // '0' -> 0
    return c - '0';
}

char int_to_ascii(int num) { // 97 -> 'a'
    return num;
}

int ascii_to_int(char c) { // 'a' -> 97
    return c;
}
