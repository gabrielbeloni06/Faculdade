import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;
public class Anagrama{
    public static String converter(String s){
        char[] letras = s.toCharArray();
        for(int i=0;i<letras.length;i++){
            char c=letras[i];
            if(c>='A' && c<='Z') letras[i]=(char)(c+32);
        }
        return new String(letras);
    }
    public static boolean procedimento(String a, String b){
        a=converter(a);
        b=converter(b);
        if(a.length()!=b.length()) return false;
        int c[]=new int[256];
        for(int i=0;i<a.length();i++){
            c[a.charAt(i)]++;
            c[b.charAt(i)]--;
        }
        for(int i=0;i<c.length;i++){
            int verificar=c[i];
            if(verificar!=0) return false;
        }
        return true;
    }
    public static void main(String[] args){
            Scanner scanner = new Scanner(System.in,StandardCharsets.UTF_8);
            String tag = "FIM";
            PrintStream out = new PrintStream(System.out, true, StandardCharsets.UTF_8);
            while(scanner.hasNext()){
                String entrada = scanner.nextLine();
                if (entrada.equals(tag)) break;
                String[] div = entrada.split (" - ");
                if(div.length==2){
                    String strA = div[0];
                    String strB = div[1];
                    if(procedimento(strA,strB)==true) out.println("SIM");
                    else out.println("NÃO");
                }
            }
            scanner.close();
            out.close();
    }
}