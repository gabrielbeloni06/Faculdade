public class ShellSimples {
    public int tamanho(){
        int n=0;
        for(Celula i=primeiro.prox;i!=null;i=i.prox)n++;
        return n;
    }
    private Celula no(int valor) throws Exception{
        int n=tamanho();
        if(valor<0 || valor>=n) throw new Exception("Erro!");
        Celula i = primeiro.prox;
        for(int k=0;k<valor;k++) i=i.prox;
        return i;
    }
    public void Shellsort() throws Exception{
        int n = tamanho();
        if(n<=1) throw new Exception("Erro!");
        int gap =1;
        while(gap<n/3) gap = 3*gap+1;
        while(gap>0){
            for(int i=gap;i<n;i++){
                int tmp = no(i).elemento;
                int j = i;
                while(j>=gap && no(j-gap).elemento >tmp){
                    no(j).elemento = no(j-gap).elemento;
                    j-=gap;
                }
                no(j).elemento=tmp;
            }
            gap = (gap-1)/3;
        }
    }
}
