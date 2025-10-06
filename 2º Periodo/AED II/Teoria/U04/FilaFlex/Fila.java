public class Fila {
    private Celula primeiro, ultimo;
    public Fila(){
        primeiro = new Celula();
        ultimo = primeiro;
    }
    public void inserir(int x){
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }
    public int remover() throws Exception{
        if(primeiro==ultimo) throw new Exception("Erro!");
        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        int elemento = primeiro.elemento;
        tmp.prox = null;
        tmp=null;
        return elemento;
    }
    //EXERCÍCIO 1
    public void mostrar(){
        for(Celula i=primeiro.prox;i!=null;i=i.prox){
            System.out.println(i.elemento);
        }
    }
    
    //EXERCÍCIO 2
        //Apenas mostrar a execução do código presente no slide.

    //EXERCÍCIO RESOLVIDO 1
    public int removTres()throws Exception{
        if(primeiro==ultimo) throw new Exception("Erro!");
        Celula tmp = primeiro.prox;
        primeiro.prox = primeiro.prox.prox;
        int elemento = tmp.elemento;
        tmp.prox=null;
        tmp=null;
        return elemento;
    }

    //EXERCÍCIO RESOLVIDO 2
    public int maior() throws Exception{
        int maior= -1;
        if(primeiro == ultimo) throw new Exception("Erro!");
        maior = primeiro.prox.elemento;
        Celula i = primeiro.prox.prox;
        while(i!=null){
            if(i.elemento>maior) maior=i.elemento;
            i=i.prox;
        }
        return maior;
    }

    //EXERCÍCIO RESOLVIDO 3
    public int terceiroElemento(){
        return primeiro.prox.prox.prox.elemento;
    }

    //EXERCÍCIO RESOLVIDO 4
    public int soma(){
        int result=0;
        for(Celula i=primeiro;i!=null;i=i.prox) result+=i.elemento;
        return result;
    }

    //EXERCÍCIO RESOLVIDO 5
    public void inverter(){
        Celula fim = ultimo;
        while(primeiro!=fim){
            Celula nova =  new Celula(primeiro.prox.elemento);
            nova.prox=fim.prox;
            fim.prox=nova;
            Celula tmp = primeiro.prox;
            primeiro.prox = tmp.prox;
            nova=tmp=tmp.prox=null;
            if(ultimo==fim) ultimo=ultimo.prox;
        }
        fim=null;
    }   

    //EXERCÍCIO RESOLVIDO 6
    public int contarRec(){return contarRec(primeiro.prox);}
    public int contarRec(Celula i){
        int result;
        if(i==null) result=0;
        else if(i.elemento%2==0 && i.elemento%5==0) result=1+contarRec(i.prox);
        else result=contarRec(i.prox);
        return result;
    }

    //EXERCÍCIO RESOLVIDO 7
    public Celula toFila(Celula topo){
        Celula primeiro = new Celula();
        Celula ultimo = primeiro;
        ultimo = toFila(topo,ultimo);
        return primeiro;
    }
    public Celula toFila(Celula i, Celula ultimo){
        if(i!=null){
            ultimo = toFila(i.prox,ultimo);
            ultimo.prox = new Celula(i.elemento);
            ultimo = ultimo.prox;
        }
        return ultimo;
    }
}
