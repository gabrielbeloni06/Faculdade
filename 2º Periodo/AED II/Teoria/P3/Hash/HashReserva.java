public class HashReserva{
    int tabela[];
    int m1,m2,m,reserva;
    final int NULO -1;
    public HashReserva(){
        this(13,7);
    }
    public HashReserva(int m1, int m2){
        this.m1 = m1;
        this.m2 = m2;
        this.m = m1 + m2;
        this.tabela = new int[this.m];
        for(int i = 0; i < m; i++){
            tabela[i] = NULO;
        }
        reseva = 0;
    }
    public int h(int elemento){
        return elemento % m1;
    }
    public boolean inserir(int elemento){

    }
    public boolean pesquisar(int elemento){
        
    }
}