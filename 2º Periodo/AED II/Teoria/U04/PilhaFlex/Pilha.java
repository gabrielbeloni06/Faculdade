public class Pilha{
    private Celula topo;
    public Pilha(){
        topo = null;
    }
    public void inserir(int x){
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    }
    public int remover()throws Exception{
        if(topo==null){
            throw new Exception("Erro!");
        }
        int elemento = topo.elemento;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        return elemento;
    }
    public void mostrar(){
        System.out.print("[");
        for(Celula i = topo;i!=null;i=i.prox){
            System.out.print(i.elemento + " ");
        }
        System.out.print("]");
    }

    //EXERCÍCIO 01
    public int soma(){
        int soma = 0;
        for(Celula i = topo;i!=null;i=i.prox){
            soma+=i.elemento;
        }
        return soma;
    }
    //EXERCÍCIO 01
    public int recSoma(){
        if(this.topo==null) return 0;
        else{
            int copy = this.topo.elemento;
            Celula inicial = this.topo;
            this.topo=this.topo.prox;
            int soma = this.recSoma();
            this.topo=inicial;
            return copy + soma;
        }
    }
    //EXERCÍCIO 02
    public int maior()throws Exception{
        if(this.topo==null) throw new Exception("Erro!");
        int maior = this.topo.elemento;
        for(Celula i=topo;i!=null;i=i.prox){
            if(maior<i.elemento) maior =i.elemento;
        }
        return maior;
    }
    //EXERCÍCIO 03
    public int recMaior(Celula atual){
        if(atual.prox==null) return atual.elemento;
        else {
            int maior = recMaior(atual.prox);
            if(atual.elemento>maior) return atual.elemento;
            else return maior;
        }
    }
    //EXERCÍCIO 04
    public void recRemov(Celula num){
        if(num==null) return;
        else{
            System.out.println(num.elemento);
            recRemov(num.prox);
        }
    }
    //EXERCÍCIO 05
    public void recInser(Celula num){
        if(num==null)return;
        else{
            recInser(num.prox);
            System.out.println(num.elemento);
        }
    }
    //EXERCÍCIO 06
    public void mostrarInser(){
        int count=0;
        for(Celula i=topo;i!=null;i=i.prox){
            count++;
        }
        int[] array= new int[count];
        Celula valor = this.topo;
        for(int i =0 ;i<count;i++){
            array[i]=valor.elemento;
            valor=valor.prox;
        }
        for(int i=count-1;i>=count;i--){
            System.out.println(array[i]);
        }
    }
    //EXERCÍCIO 07
    //-> CÓDIGO DA PILHA
}