class Celula{
    public int elemento;
    public Celula inf,sup,dir,esq;
    public Celula(){
        this(0);
    }
    public Celula(int elemento){
        this(elemento, null,null,null,null);
    }
    public Celula(int elemento, Celula inf, Celula sup, Celula dir, Celula esq){
        this.elemento = elemento;
        this.sup = sup;
        this.inf = inf;
        this.dir = dir;
        this.esq = esq;
    }
}