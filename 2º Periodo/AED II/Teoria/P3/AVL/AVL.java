public class AVL{
    private No raiz;
    pulbic boid inserir(int x )throws Exception{
        raiz =  inserir(x, No i);
    }
    private No inserir(int x, No i)throws Exception{
        if(i == null){
            i = new No(x);
        }else if(x < i.elemento){
            i.esq = inserir(x, i.esq);
        }else if(x > i.elemento){
            i.dir = inserir(x, i.dir);
        }else{
            throw new Exception();
        }
        return balancear(i);
    }
    private No balancear(No no)throws Exception{
        if( no != null){
            int fator = No.getNivel(no.dir) - No.getNivel(no.esq);
            if(Math.abs(fator) <= 1){
                no.setNivel();
            }else if(fator == 2){
                int fatorFilhoDir = no.getNivel(no.dir.dir) - No.getNivel(no.dir.esq);
                if(fatorFilhoDir == -1){
                    no.dir = rotacionarDir(no.dir);
                }
                no = rotacionarEsq(no);
            }else if(fator == -2){
                int fatorFilhoEsq = no.getNivel(no.esq.dir) - No.getNivel(no.esq.esq);
                if(fatorFilhoEsq == 1){
                    no.esq = rotacionarEsq(no.esq);
                }
                no = rotacionarDir(no);
            }
        }
        return no;
    }
}