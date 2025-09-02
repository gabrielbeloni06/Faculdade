import util.java.Scanner;
public class Sort{
	public static void swap(int menor,int j){
		copy=array[i];
                        array[i]=array[menor];
                        array[menor]=copy;

	}
	public static void ordenar(int v[],int mod){
		int n=array.length();
		int copy;
		for(int i=0;i<(n-1);i++){
			int menor=i;
			for(j=(i+1);j<n;j++){
				if(array[menor % mod]>array[j % mod]){
					menor=j;
				}
				if(array[menor % mod]==array[j % mod]){ //Se forem iguais verificar se:
					if(array[menor%2]==0 && array[j%2]==0){ //Se ambos pares
						if(array[menor]>array[j]){ //O menor par vai na frente
							swap(j,menor);
						}
					}
					else{
						if(array[menor]>array[j]){
							swap(menor,j);
						}
						else{
						
						}
					}			
				}
			}
		}
	}
	public static main void(String[] args){
		Scanner scanner = new Scanner(System.in);
		int n,m;
		while(m!=0){
		n=scanner.nextInt();
		m=scanner.nextInt();
		int valor[n];
		for(int i=0;i<(n-1);i++){
			valor[i]=nextInt();
			for(int j=(i+1);j<n;j++){
			int menor=i;
			valor[i]%m=mod[i];
			if(mod[i]>mod[j]) menor=j;
				copy=
			if(valor[i]%2==0) pi[i]=0;
                        else pi[i]=1;
			}
		}
		}
	}
}
