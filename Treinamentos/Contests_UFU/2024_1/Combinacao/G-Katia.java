/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/

import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class combina {

    static Map<String, BigInteger> m = new HashMap<>();

    static String decimalToBinary(BigInteger dec, int casas) {
        StringBuilder binary = new StringBuilder();

        while (!dec.equals(BigInteger.ZERO)) {
            binary.insert(0, dec.and(BigInteger.ONE));
            dec = dec.shiftRight(1);
        }

        while (binary.length() < casas) { binary.insert(0, '0'); }
 
        m.put(binary.toString(), dec);

        return binary.toString();
    }

    static int countOnes(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                count++;
            }
        }
        return count;
    }

    static BigInteger binaryToDecimal(String bin) {
        BigInteger dec = BigInteger.ZERO;
        for (int i = 0; i < bin.length(); i++) {
            if (bin.charAt(i) == '1') {
                dec = dec.add(BigInteger.ONE.shiftLeft(bin.length() - i - 1));
            }
        }
        return dec;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        String[] parts = s.split(",");
        List<String> v = new ArrayList<>(Arrays.asList(parts));
        List<String> binarios = new ArrayList<>();

        for (int i = 1; i <= (1 << v.size()) - 1; i++) {
            binarios.add(decimalToBinary(BigInteger.valueOf(i), v.size()).toString());
        }

        Collections.sort(binarios, (s1, s2) -> {
            int c1 = countOnes(s1);
            int c2 = countOnes(s2);
            if (c1 != c2) {
                if(c1 < c2) return 1;
                else return -1;
            }
            return binaryToDecimal(s1).compareTo(binaryToDecimal(s2));
        });

        // reverse binarios
        Collections.reverse(binarios);

  

        for (String bin : binarios) {
            StringBuilder aux = new StringBuilder();
            for (int i = 0; i < bin.length(); i++) {
                if (bin.charAt(i) == '1') {
                    aux.append(v.get(i)).append(",");
                }
            }
            if (aux.length() > 0) {
                aux.deleteCharAt(aux.length() - 1);
                bw.write(aux.toString());
                bw.newLine();
            }
        }

        bw.flush();
    }



}
