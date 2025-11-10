class DeToBi{
    public int converter(int x){
        int resto = x % 2;
        int div = x / 2;
        Pilha.inserir(resto);
        if(div > 0){
            converter(div);
        }
    }

    public void imprimirBi(){
        int valor;
        while((valor == Pilha.remover()) != null){
            System.out.println(valor);
        }
    }
}