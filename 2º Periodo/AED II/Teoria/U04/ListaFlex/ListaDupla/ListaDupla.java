public class ListaDupla {
    //Exercícios
    //Exercício 01
    public void inverterDupla throw Exception{
        if(primeiro==ultimo) throw new Exception("Erro!");
        Celula i = primeiro.prox;
        Celula j = ultimo;
        Celula tmp = null;
        while(i!=null){
            tmp = i.elemento;
            i.j=i.prox;
            i.prox=tmp;
            i=i.j;
        }
        tmp = ultimo;
        ultimo = primeiro.prox;
        primeiro.prox = tmp;
        tmp.j = primeiro;
        ultimo.prox=null;
    }
}
