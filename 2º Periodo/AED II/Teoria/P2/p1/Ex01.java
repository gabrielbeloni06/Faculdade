class CelulaLista{
    CelulaPilha topo;
    CelulaLista prox;
}
class CelulaPilha{
    int elemento;
    CelulaPilha prox;
}
class Lista{
    CelulaLista inicio;
    CelulaLista fim;
    public CelulaLista maiorPilha(){
        if(inicio == null) return;
        CelulaLista maior = inicio;
        int maiorTam = contar(maior.topo);
        CelulaLista i = inicio.prox;
        while(i != null){
            int tamAtual = contar(i.topo);
            if(tamAtual > maiorTam){
                maiorTam = tamAtual;
                maior = i;
            }
            i = i.prox;
        }
        return maior;
    }
}
class Ex01{
    //so para nomear arquivo
}