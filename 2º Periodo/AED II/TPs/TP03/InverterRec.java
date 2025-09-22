import java.util.Scanner;
public class InverterRec{
    public static void inverter(String s){
        char[] arrayDeChars = s.toCharArray();
        inverterRec(arrayDeChars,0,s.length()-1);
    }
    private static void inverterRec(char[] array,int i,int j){
        if (i>=j) { //CASO BASE, SE FOR MAIOR OU IGUAL A J, JA PERCORREMOS A STRING INTEIRA
            System.out.println(new String(array));
            return;
        }
        //TROCA OS CARCTERES DAS PONTAS PARA INVERTER A STRING
        char temp=array[i];
        array[i]=array[j];
        array[j]=temp;
        // CHAMA A FUNÇÃO NOVAMENTE, ASSIM AUMENTO I E DIMINUIO J PARA INVERTER OS PRÓXIMOS CARACTERES
        inverterRec(array,i+1,j-1);
    }
    //NÃO PRECISEI ALTERAR NADA NA MAIN
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        String str=scanner.nextLine();
        String tag="FIM";
        while(!str.equals(tag)){
            inverter(str);
            str = scanner.nextLine();
        }
        scanner.close();
    }
}