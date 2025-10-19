public class QuicksortDupla {
    public void quicksort()throws Exception{
        Celula inicio = primeiro.prox;
        Celula fim = ultimo;
        quicksort(inicio,fim);
    }
    public void quicksort(Celula esq, Celula dir){
        while(dir!=null && esq != dir && esq !=dir.prox){
            int pivo = dir.elemento;
            Celula i = esq.ant;
            for(Celula j = esq; j != dir;j=j.prox){
                if(j.elemento <= pivo){
                    if(i==null) i = esq;
                    else i = i.prox;
                    int tmp = i.elemento;
                    i.elemento = j.elemento;
                    j.elemento = tmp;
                }   
            }
            if(i==null)i=esq;
            else i=i.prox;
            int tmp = i.elemento;
            i.elemento = dir.elemento;
            dir.elemento=tmp;
            Celula pFinal=i;
            int tamE= no(esq,pFinal.ant);
            int tamD = no(pFinal.prox, dir);
            if(tamE<tamD){
                quicksort(esq,pFinal.ant);
                esq=pFinal.prox;
            }
            else{
                quicksort(pFinal.prox,dir);
                dir=pFinal.ant;
            }
        }
    }
    private int no(Celula inicio, Celula fim){
        if(inicio==null||fim==null||inicio.ant==fim) return 0;
        int count=0;
        Celula tmp=inicio;
        while(tmp!=fim.prox && tmp!=null){
            count++;
            tmp = tmp.prox;
        }
        return count;
    }
}
