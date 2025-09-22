import java.util.Random;
import java.util.Scanner;
public class random {
    public static String substituirLetras(String s, Random gerador) {
        char letraSorteada1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        char letraSorteada2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == letraSorteada1) {
                sb.append(letraSorteada2);
            } else {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String linha;
        Random gerador = new Random();
        gerador.setSeed(4);
        while (!(linha = sc.nextLine()).equals("FIM")) {
            System.out.println(substituirLetras(linha, gerador));
        }

        sc.close();
    }
}