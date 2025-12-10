public class AVN{
    private NoAN raiz;
    private void inserir (int elemento, NoAN bisavo, NoAN avo,NoAN pai, NoAN i)throws Exception{
        if(i == null){
            if(elemento < pai.elemento){
                i = pai.esq = new NoAN(elemento, true);
            }else{
                i = pai.dir = new NoAN(elemento, true);
            }
            if(pai.cor == true){
                balancear(bisavo, avo, pai, i);
            }
        }else{
            if(i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true){
                i.cor = true;
                i.esq.cor = i.dir.cor = false;
                if(i == raiz){
                    i.cor = false;
                }else if(pai.cor = true){
                    balancear(bisavo, avo, pai, i);
                }
            }
            if(elemento < i.elemento){
                inserir(elemento, avo, pai, i , i.esq);
            }else if(elemento > i.elemento){
                inserir(elemento, avo, pai, i, i.dir);
            }else{
                throw new Exception();
            }
        }
    }
    private void balancear(NoAN bisavo, NoAN avo, NoAN pai, NoAN i){
        if(pai.cor == true){
            if(pai.elemento > avo.elemento){
                avo = rotEsq(avo);
            }else{
                avo = rotDirEsq(avo);
            }
        }else{
            if(i.elemento < pai.elemento){
                avo = rotDir(avo);
            }else{
                avo = rotEsq(avo);
            }
        }
        if(bisavo == null) raiz = avo;
        else if (avo.elemento < bisavo.elemento) bisavo.esq = avo;
        else bisavo.dir = avo;
        avo.cor = false;
        avo.esq.cor = avo.dir.cor = true;
    }
}