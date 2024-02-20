public static void BbigInteger() {
    
    BigInteger a = BigInteger.valueOf(1000000000);
                a = new BigInteger("10000000000");

    // Operações com inteiros grandes
    BigInteger  arit = a.add(a);
                arit = a.subtract(a);
                arit = a.multiply(a);
                arit = a.divide(a);
                arit = a.mod(a);

    // Comparação
    boolean bool = a.equals(a);
            bool = a.compareTo(a) > 0;
            bool = a.compareTo(a) < 0;
            bool = a.compareTo(a) >= 0;
            bool = a.compareTo(a) <= 0;

    // Conversão para string
    String m = a.toString();

    // Conversão para inteiro
    int     _int = a.intValue();
    long   _long = a.longValue();
    double _doub = a.doubleValue();

    // Potência
    BigInteger _pot = a.pow(10);
    BigInteger _sqr = a.sqrt();

}

public static void BigDecimal() {

    BigDecimal a = new BigDecimal("10000000000");
                a = new BigDecimal("10000000000.0000000000");
                a = BigDecimal.valueOf(1000000000, 10); 


    // Operações com reais grandes
    BigDecimal arit = a.add(a);
                arit = a.subtract(a);
                arit = a.multiply(a);
                arit = a.divide(a);
                arit = a.remainder(a);

    // Comparação
    boolean bool = a.equals(a);
            bool = a.compareTo(a) > 0;
            bool = a.compareTo(a) < 0;
            bool = a.compareTo(a) >= 0;
            bool = a.compareTo(a) <= 0;

    // Conversão para string
    String m = a.toString();

    // Conversão para inteiro
    int     _int = a.intValue();
    long   _long = a.longValue();
    double _doub = a.doubleValue();

    // Potência
    BigDecimal _pot = a.pow(10);
}