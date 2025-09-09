import java.util.Scanner;
public class Grid{
    public static void insertionSort(Scanner scan){
        while (scan.hasNext()){
            int n = scan.nextInt();
            int[] grid = new int[n];
            int[] chegada = new int[n];
            for (int i=0;i<n;i++){
                grid[i]=scan.nextInt();
            }
            for (int i=0;i<n;i++){
                chegada[i]=scan.nextInt();
            }
            int count=0;
            for (int i=0;i<n;i++){
                if (grid[i]!=chegada[i]){
                    int cmp=chegada[i];
                    int j=i;
                    while (j<n && grid[j]!=cmp) {
                        j++;
                    }
                    int tmp=grid[j];
                    for (int k=j;k>i;k--) {
                        grid[k]=grid[k-1];
                        count++;
                    }
                    grid[i]=tmp;
                }
            }
            System.out.println(count);
        }
    }
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        insertionSort(scan);
    }
}

