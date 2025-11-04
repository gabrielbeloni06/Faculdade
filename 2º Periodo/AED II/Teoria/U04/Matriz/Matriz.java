class Matriz{
    private Celula inicio;
    private int linha, coluna;
    public Matriz(){
        this(2,2);
    }
    public Matriz(int linha, int coluna){
        this.linha = linha;
        this.coluna = coluna;
        inicio = new Celula();
        Celula atual = inicio;
        for(int j=1;j<coluna;j++){
            atual.dir = new Celula();
            atual.dir.esq = atual;
            atual = atual.dir;
        }
        Celula linhaAcima=inicio;
        for(int i = 1;i<linha;i++){
            Celula LinhaAtual =  new Celula();
            linhaAcima.inf = LinhaAtual;
            LinhaAtual.sup = linhaAcima;
            atual = linhaAtual;
            Celula acima = linhaAcima.dir;
            for(int j = 1; j<coluna;j++){
                atual.dir = new Celula();
                atual.dir.esq = atual;
                atual = atual.dir;
                atual.sup = acima;
                acima.inf = atual;
                acima = acima.dir;
            }
            linhaAcima = linhaAcima.inf;
        }
    }

    public Matriz soma(Matriz m){
        Matriz resp = null;
        if(this.linha == m.linha && this.coluna == m.coluna){}
    }
}