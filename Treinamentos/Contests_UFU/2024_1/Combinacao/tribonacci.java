import java.util.Arrays;
import java.math.BigInteger;

class tribonacci {

    static BigInteger[] dp;

    static BigInteger fibonacciDP(int n) {
        if (n < 3) return dp[n] = BigInteger.ONE;
        if (dp[n] != null) return dp[n];
        return dp[n] = fibonacciDP(n - 1).add(fibonacciDP(n - 2)).add(fibonacciDP(n - 3));
    }

    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int n = sc.nextInt();
        dp = new BigInteger[n + 1];
        Arrays.fill(dp, null);

        System.out.println(fibonacciDP(n-1));

    }
}
