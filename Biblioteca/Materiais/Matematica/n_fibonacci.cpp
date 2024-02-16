int dp[MAX];

int fibonacciDP(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonacciDP(n-1) + fibonacciDP(n-2);
}

int nFibonacci(int minus, int times, int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    int aux = 0;
    for(int i=0; i<times; i++) {
        aux += nFibonacci(minus, times, n-minus);
    }
}