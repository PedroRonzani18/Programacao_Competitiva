import java.math.BigInteger;
import java.util.Scanner;

public class escoteiros {

    public static void main(String[] args) {
        Scanner e = new Scanner(System.in);
        int n, aux;
        BigInteger mult = BigInteger.ONE;

        n = e.nextInt();

        for (int i = 0; i < n; i++) {
            aux = e.nextInt();
            mult = mult.multiply(BigInteger.valueOf(aux));
        }

        if (n == 0)
            System.out.println(0);
        else
            System.out.println(mult);
    }
}