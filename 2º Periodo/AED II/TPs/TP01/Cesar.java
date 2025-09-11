import java.util.Scanner;
public class Cesar {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s;
        String tag = "FIM";
        int peso = 3;
        s = scanner.nextLine();
        while (!s.equals(tag)) {
            String var = "";
            for (int i = 0; i < s.length(); i++) {
                char caractere = s.charAt(i);
                if (caractere == '\uFFFD') {
                    var += caractere;
                } else {
                    var += (char) (caractere + peso);
                }
            }
            System.out.println(var);
            s = scanner.nextLine();
        }
        scanner.close();
    }
}