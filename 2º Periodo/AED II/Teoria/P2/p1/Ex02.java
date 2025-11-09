class No{
    char letra;
    No esq, dir;
    No2 raiz;
}

class No2{
    String palavra;
    No2 esq, dir;
}

class ArvoreArvore{
    No raiz;

    public int contarPalavras(String padrao){
        if((raiz == null) || (padrao == null)){
            return 0;
        }
        char letraInicial = padrao.charAt(0);
        int tam = padrao.length;
        No i = raiz;
        while(i != null){
            if(letraInicial == i.letra){
                return contarNaArvoreSecundaria(i.raiz, tam);
            }else if(letraInicial < i.letra){
                i = i.esq;
            }else{
                i = i.dir;
            }
        }
        return 0;
    }

    private int contarNaArvoreSecundaria(No2 raiz2, int tam){
        if(raiz2 == null){
            return 0;
        }
        int count = 0;
        if(raiz2.palavra.length() == tam){
            count++;
        }
        count += contarNaArvoreSecundaria(raiz2.esq, tam);
        count += contarNaArvoreSecundaria(raiz2.dir, tam);
        return count;
    }
}

class Ex02{
    //nomear arquivo
}