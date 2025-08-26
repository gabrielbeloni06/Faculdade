import java.util.Scanner;
public class Espelho{
	public static String reverse(String x){
		String result = "";
		for(int i=x.length()-1;i>=0;i--){
			result +=x.charAt(i);
		}
		return result;
	}
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
		do{
			String str = scanner.nextLine();
			String vet[] = str.split(" ");
			for(String x : vet){
				System.out.print(reverse(x)+" ");
			}
			System.out.println("");
			//System.out.println(str)
			//System.out.println(reverse(vet[0])+" "+reverse(array[1]));
		}
		while (scanner.hasNextLine());
	}
}

