int factdp[20]; 

int fact(int n) {
    if (n < 2) return 1;
    if (factdp[n] != 0) return factdp[n];
    return factdp[n] = n * fact(n - 1);
}