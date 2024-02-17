import java.math.BigInteger;
import java.util.Scanner;

public class hackathon {

    static BigInteger factdp[] = new BigInteger[101];

    public static BigInteger fact(int n) {
        if (n < 2)
            return BigInteger.ONE;
        if (factdp[n] != BigInteger.ZERO)
            return factdp[n];
        return factdp[n] = fact(n - 1).multiply(BigInteger.valueOf(n));
    }

    public static void main(String[] args) {

        for (int i = 0; i < 101; i++) {
            factdp[i] = BigInteger.ZERO;
        }

        Scanner e = new Scanner(System.in);

        int n, f;

        n = e.nextInt();
        f = e.nextInt();

        while (!(n == 0 && f == 0)) {
            System.out.println(fact(n).divide(fact(n - f).multiply(fact(f))));
            n = e.nextInt();
            f = e.nextInt();
        }

    }

}
