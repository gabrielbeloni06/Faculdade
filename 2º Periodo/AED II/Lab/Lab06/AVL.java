import java.util.scanner;
class AVL{
	//04 - Validação de nível
	public void 
}
class No{
	//01 - Adicionar Atributo Nivel
        public int elemento, nivel;
        public No esq, dir;
        public No(int elemento){
                this(elemento,null,null);
        }
        public No(int elemento, int nivel, No esq, No dir){
                this.elemento = elemento;
		this.nivel = nivel;
                this.esq = esq;
                this.dir = dir;
        }
	//02 - Adicionar Metodo SetNivel
	public void setNivel(){
		this.nivel = 1 + getNivel(no.dir) - getNivel(no.esq); 
	}
	public void getNivel(No no){
		if(no == null) return this.nivel = 0;
		else return no.nivel;
	}
}

class NoBin{
	public int elemento;
	public No esq, dir;
	public No(int elemento){
		this(elemento,null,null);
	}
	public No(int elemento, No esq, No dir){
		this.elemento = elemento;
		this.esq = esq;
		this.dir = dir;
	}
}
public class ArvoreBinaria {
	private No raiz;

	public ArvoreBinaria() {
		raiz = null;
	}

	public boolean pesquisar(int x) {
		return pesquisar(x, raiz);
	}

	private boolean pesquisar(int x, No i) {
      boolean resp;
		if (i == null) {
         resp = false;

      } else if (x == i.elemento) {
         resp = true;

      } else if (x < i.elemento) {
         resp = pesquisar(x, i.esq);

      } else {
         resp = pesquisar(x, i.dir);
      }
      return resp;
	}
	public void caminharCentral() {
		System.out.print("[ ");
		caminharCentral(raiz);
		System.out.println("]");
	}
	//6 - Impressão do nível do No
	private void caminharCentral(No i) {
		if (i != null) {
			caminharCentral(i.esq); // Elementos da esquerda.
			System.out.print(i.elemento + i.nivel + " "); // Conteudo do no.
			caminharCentral(i.dir); // Elementos da direita.
		}
	}

	public void caminharPre() {
		System.out.print("[ ");
		caminharPre(raiz);
		System.out.println("]");
	}

	private void caminharPre(No i) {
		if (i != null) {
			System.out.print(i.elemento + " "); // Conteudo do no.
			caminharPre(i.esq); // Elementos da esquerda.
			caminharPre(i.dir); // Elementos da direita.
		}
	}

	public void caminharPos() {
		System.out.print("[ ");
		caminharPos(raiz);
		System.out.println("]");
	}

	private void caminharPos(No i) {
		if (i != null) {
			caminharPos(i.esq); // Elementos da esquerda.
			caminharPos(i.dir); // Elementos da direita.
			System.out.print(i.elemento + " "); // Conteudo do no.
		}
	}

	public void inserir(int x) throws Exception {
		raiz = inserir(x, raiz);
	}

	private No inserir(int x, No i) throws Exception {
		if (i == null) {
         i = new No(x);

      } else if (x < i.elemento) {
         i.esq = inserir(x, i.esq);

      } else if (x > i.elemento) {
         i.dir = inserir(x, i.dir);

      } else {
         throw new Exception("Erro ao inserir!");
      }

		return balancear(i);
	}
	//8 - Metodo Balancear
	public No balancear(No i){
		int n = getNivel(i);
		if(n == 0 || n == 1 || n == -1){
			return i;
		}else if(n == 2){
			rotEsq(i);
		}
		else{
			rotDir(i);
		}
		no.setNivel(i);
	}

	public No rotDir(){
		No noDir = no.dir;
		No noEsq = no.esq;
		No noDirEsq = noDir.esq;
		No noEsqDir = noEsq.dir;
		no.setNivel();
		noEsq.setNivel;
		return noEsq;

	}

	public void rotEsq(){
		No noDir = no.dir;
		No noEsq = no.esq;
		No noDirEsq = noDir.esq;
		No noEsqDir = noEsq.dir;
		no.setNivel();
		noDir.setNivel;
		return noDir;
	}

	public void inserirPai(int x) throws Exception {
      if(raiz == null){
         raiz = new No(x);
      } else if(x < raiz.elemento){
		   inserirPai(x, raiz.esq, raiz);
      } else if(x > raiz.elemento){
		   inserirPai(x, raiz.dir, raiz);
      } else {
         throw new Exception("Erro ao inserirPai!");
      }
	}

	private void inserirPai(int x, No i, No pai) throws Exception {
		if (i == null) {
         if(x < pai.elemento){
            pai.esq = new No(x);
         } else {
            pai.dir = new No(x);
         }
      } else if (x < i.elemento) {
         inserirPai(x, i.esq, i);
      } else if (x > i.elemento) {
         inserirPai(x, i.dir, i);
      } else {
         throw new Exception("Erro ao inserirPai!");
      }
	}


	/**
	 * Metodo publico iterativo para remover elemento.
	 * @param x Elemento a ser removido.
	 * @throws Exception Se nao encontrar elemento.
	 */
	public void remover(int x) throws Exception {
		raiz = remover(x, raiz);
	}

	/**
	 * Metodo privado recursivo para remover elemento.
	 * @param x Elemento a ser removido.
	 * @param i No em analise.
	 * @return No em analise, alterado ou nao.
	 * @throws Exception Se nao encontrar elemento.
	 */
	private No remover(int x, No i) throws Exception {

		if (i == null) {
         throw new Exception("Erro ao remover!");

      } else if (x < i.elemento) {
         i.esq = remover(x, i.esq);

      } else if (x > i.elemento) {
         i.dir = remover(x, i.dir);

      // Sem no a direita.
      } else if (i.dir == null) {
         i = i.esq;

      // Sem no a esquerda.
      } else if (i.esq == null) {
         i = i.dir;

      // No a esquerda e no a direita.
      } else {
         i.esq = maiorEsq(i, i.esq);
		}

		return i;
	}

	/**
	 * Metodo para trocar o elemento "removido" pelo maior da esquerda.
	 * @param i No que teve o elemento removido.
	 * @param j No da subarvore esquerda.
	 * @return No em analise, alterado ou nao.
	 */
	private No maiorEsq(No i, No j) {

      // Encontrou o maximo da subarvore esquerda.
		if (j.dir == null) {
			i.elemento = j.elemento; // Substitui i por j.
			j = j.esq; // Substitui j por j.ESQ.

      // Existe no a direita.
		} else {
         // Caminha para direita.
			j.dir = maiorEsq(i, j.dir);
		}
		return j;
	}

	/**
	 * Metodo que retorna o maior elemento da árvore
	 * @return int maior elemento da árvore
	 */
   public int getMaior(){
      int resp = -1;

      if(raiz != null){
         No i;
         for(i = raiz; i.dir != null; i = i.dir);
         resp = i.elemento;
      }

      return resp;
   }

   public int getMenor(){
      int resp = -1;

      if(raiz != null){
         No i;
         for(i = raiz; i.esq != null; i = i.esq);
         resp = i.elemento;
      }

      return resp;
   }

   public int getAltura(){
      return getAltura(raiz, 0);
   }

   public int getAltura(No i, int altura){
      if(i == null){
         altura--;
      } else {
         int alturaEsq = getAltura(i.esq, altura + 1);
         int alturaDir = getAltura(i.dir, altura + 1);
         altura = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
      }
      return altura;
   }

