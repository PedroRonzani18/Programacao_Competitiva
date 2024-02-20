static BigInteger[] dp = new BigInteger[1000000];

public static BigInteger factorialDP(BigInteger n) {
    dp[0] = BigInteger.ONE;
    for (int i = 1; i <= n.intValue(); i++) {
        dp[i] = dp[i - 1].multiply(BigInteger.valueOf(i));
    }
    return dp[n.intValue()];
}