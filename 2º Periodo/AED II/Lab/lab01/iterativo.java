import java.util.Scanner;
public class iterativo{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		String tag="FIM";
		String s;
		s = scanner.nextLine();
		while(!s.equals(tag)){
			int count=0;
			for(int i=0;i<s.length();i++){
				char l = s.charAt(i);
				if(l>='A'&& l<='Z') count++;
			}
			System.out.println(count);
			s=scanner.nextLine();
		}
		scanner.close();
	}
}
