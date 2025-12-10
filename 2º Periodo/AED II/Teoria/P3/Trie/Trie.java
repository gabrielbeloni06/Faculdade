class No{
    public char elemento;
    public No[] prox;
    public boolean folha;
    public No(){
        this(' ');
    }
    public No(char c){
        this.elemento = c;
        this.prox = new No [256];
        this.folha = false;
    }
}
    public class Trie{
        private No raiz;
        public Trie(){
            raiz = new No();
        }
        public void inserir(String s)throws Exception{
            inserir(s, raiz, 0);
        }
        private void inserir(String s, No no, int i){
            char letra = s.charAr(i);
            if(no.prox[letra] == null){
                no.prox[letra] = new No(letra);
                if(i == s.length() - 1){
                    no.prox[letra].folha = true;
                }else{
                    inserir(s, no.prox[letra], i + 1);
                }
            }else{
                if(i < s.length() - 1){
                    inserir(s, no.prox[letra], i + 1);
                }else{
                    no.prox[letra].folha = true;
                }
            }
        }
        public boolean pesquisar(String s) throws Exception{
            return pesquisar(s, raiz, 0);
        }
        private boolean pesquisar(String s, No no, int i)throws Exception{
            boolean resp;
            char letra = s.charAt(i);
            if(no.prox[letra] == null){
                resp = false;
            }else if(i == s.length() - 1){
                resp = (no.prox[letra].folha == true);
            }else{
                resp = pesquisar(s, no.prox[letra], i + 1);
            }
            return resp;
        }
    }