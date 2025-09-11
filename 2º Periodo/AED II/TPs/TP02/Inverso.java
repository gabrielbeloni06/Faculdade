import java.util.Scanner;
public class Inverso{
    public static void inverter(String s){
        char[] inversa = s.toCharArray();
        int j = s.length()-1;
        for(int i=0;i<j;i++){
            char copy = inversa[i];
            inversa[i]=inversa[j];
            inversa[j]=copy;
            j--;
        }
        String result = new String(inversa);
        System.out.println(result);
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        String tag = "FIM";
        while(!str.equals(tag)){
            inverter(str);
            str = scanner.nextLine();    
        }
        scanner.close();
    }
}