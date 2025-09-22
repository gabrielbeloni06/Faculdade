import java.util.Scanner;
public class SomaRec{
    public static int somaDeDigitos(String s){
        return somaDeDigitosRec(s, 0);
    }
    //FUNÇÃO RECURSIVA QUE SOMA OS DIGITOS DE UMA STRING
    public static int somaDeDigitosRec(String s, int valor){
        if(valor==s.length()) return 0;
        //PEGA O CARACTERE ATUAL E VERIFICA SE É UM DIGITO, SE FOR CONVERTE PARA INTEIRO
        char caractereAtual=s.charAt(valor);
        int valorAtual=0;
        if(Character.isDigit(caractereAtual)) valorAtual = Character.getNumericValue(caractereAtual);
        return valorAtual + somaDeDigitosRec(s,valor+1);
    }
    //MAIN, LOOP PARA PARAR QUANDO VER A TAG FIM, ENQUANTO ISSO CHAMA A FUNÇÃO DE SOMA E IMPRIME O RESULTADO
      public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        String linha;
        while(scanner.hasNextLine()) {
            linha = scanner.nextLine();
            if(linha.equals("FIM")) break;
            int soma=somaDeDigitos(linha);
            System.out.println(soma);
        }
        scanner.close();
    }
}