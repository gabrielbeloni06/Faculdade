import java.util.Scanner;
public class recursivo{
	private static Scanner scanner = new Scanner(System.in);
	public static void recursao(){
		String tag = "FIM";
		String s;
		s=scanner.nextLine();
		int count=0;
		if(s.equals(tag)) return;
			for(int i=0;i<s.length();i++){
				char l = s.charAt(i);
				if(l>='A'&&l<='Z')count++;
			}
		System.out.println(count);
		recursao();
	}
	public static void main(String[] args){
		recursao();
		scanner.close();
	}

}
