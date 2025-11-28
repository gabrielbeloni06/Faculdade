import java.io.*;
import java.util.*;
// CLASSE NO (MUDANÇA PARA ARVORE ALVINEGRA)
class No {
    public Game game;
    public No esq, dir;
    public boolean cor;

    public No(Game game) {
        this(game, false);
    }

    public No(Game game, boolean cor) {
        this.game = game;
        this.cor = cor;
        this.esq = null;
        this.dir = null;
    }
}

// CLASSE GAME (IGUAL TP05)
class Game {
    private int id;
    private String nome;
    private String lancamento;
    private String proprietarios;
    private float preco;
    private String idiomas;
    private int metacritic;
    private float nota;
    private int conquistas;
    private String publishers;
    private String developers;
    private String categorias;
    private String generos;
    private String tags;

    public Game() {
        this.id = 0;
        this.nome = null;
    }

    public String getNome() {
        return this.nome;
    }

    //FORMATAÇÃO DE LISTAS (IGUAL TP05)
    private String formatarListaString(String s) {
        if (s == null) return null;
        String resultado = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != '\'') {
                if (c == ',') {
                    resultado += ", ";
                    if (i + 1 < s.length() && s.charAt(i + 1) == ' ') i++;
                } else {
                    resultado += c;
                }
            }
        }
        return resultado;
    }
//FORMATAÇÃO DE DATA (IGUAL TP05)
    private String formatarData(String data) {
        if (data == null || data.isEmpty()) return "";
        if (data.split(" ").length < 2) return data; 
        return data; 
    }
//METODO DE QUEBRAR LINHA CSV MANUALMENTE (IGUAL TP05)
    private static String[] quebrarLinhaCSVManual(String linha) {
        String[] campos = new String[14];
        int campoIndex = 0;
        String campoAtual = "";
        boolean dentroDeAspas = false;

        for (int i = 0; i < linha.length() && campoIndex < 14; i++) {
            char c = linha.charAt(i);
            if (c == '"') {
                if (dentroDeAspas && i + 1 < linha.length() && linha.charAt(i + 1) == '"') {
                    campoAtual += '"';
                    i++;
                } else {
                    dentroDeAspas = !dentroDeAspas;
                }
            } else if (c == ',' && !dentroDeAspas) {
                campos[campoIndex] = campoAtual;
                campoIndex++;
                campoAtual = "";
            } else {
                campoAtual += c;
            }
        }
        if (campoIndex < 14) campos[campoIndex] = campoAtual;
        return campos;
    }
//METODO DE LEITURA DO CSV (IGUAL TP05)
    public void ler(String appID) {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader("/tmp/games.csv"));
            String linha;
            br.readLine(); 
            while ((linha = br.readLine()) != null) {
                if (linha.startsWith(appID + ",")) {
                    String[] campos = quebrarLinhaCSVManual(linha);
                    if (campos[0].equals(appID)) {
                        this.id = Integer.parseInt(campos[0]);
                        this.nome = campos[1];
                        this.lancamento = formatarData(campos[2]);
                        this.proprietarios = campos[3];
                        this.preco = Float.parseFloat(campos[4]);
                        this.idiomas = formatarListaString(campos[5]);
                        this.metacritic = Integer.parseInt(campos[6]);
                        this.nota = Float.parseFloat(campos[7]);
                        this.conquistas = Integer.parseInt(campos[8]);
                        this.publishers = campos[9];
                        this.developers = campos[10];
                        this.categorias = formatarListaString(campos[11]);
                        this.generos = formatarListaString(campos[12]);
                        this.tags = formatarListaString(campos[13]);
                        break;
                    }
                }
            }
        } catch (Exception e) {
        } finally {
            try { if (br != null) br.close(); } catch (IOException e) {}
        }
    }
}
// CLASSE ARVORE ALVINEGRA
class ArvoreAlvinegra {
    private No raiz;
    public int comparacoes;
    private static final boolean RED = true;
    private static final boolean BLACK = false;
    public ArvoreAlvinegra() {
        this.raiz = null;
        this.comparacoes = 0;
    }
    private boolean isRed(No x) {
        if (x == null) return false;
        return x.cor == RED;
    }
// ROTAÇÃO ESQUERDA
    private No rotacionarEsquerda(No h) {
        No x = h.dir;
        h.dir = x.esq;
        x.esq = h;
        x.cor = h.cor;
        h.cor = RED;
        return x;
    }
//ROTAÇÃO DIREITA
    private No rotacionarDireita(No h) {
        No x = h.esq;
        h.esq = x.dir;
        x.dir = h;
        x.cor = h.cor;
        h.cor = RED;
        return x;
    }
// INVERTE CORES
    private void inverterCores(No h) {
        h.cor = !h.cor;
        if (h.esq != null) h.esq.cor = !h.esq.cor;
        if (h.dir != null) h.dir.cor = !h.dir.cor;
    }
//METODO DE INSERÇÃO
    public void inserir(Game game) throws Exception {
        raiz = inserir(raiz, game);
        raiz.cor = BLACK;
    }
// INSERÇÃO COM BALANCEAMENTO
    private No inserir(No h, Game game) throws Exception {
        if (h == null) return new No(game, RED);

        int cmp = game.getNome().compareTo(h.game.getNome());

        if (cmp < 0) {
            h.esq = inserir(h.esq, game);
        } else if (cmp > 0) {
            h.dir = inserir(h.dir, game);
        } else {
            throw new Exception("Erro ao inserir: elemento existente");
        }

        // 2. Correções da Alvinegra
        if (isRed(h.dir) && !isRed(h.esq)) {
            h = rotacionarEsquerda(h);
        }
        if (isRed(h.esq) && isRed(h.esq.esq)) {
            h = rotacionarDireita(h);
        }
        if (isRed(h.esq) && isRed(h.dir)) {
            inverterCores(h);
        }

        return h;
    }

//METODO DE PESQUISA
    public void pesquisar(String nome) {
        System.out.print(nome + ": =>raiz");
        pesquisar(raiz, nome);
    }
// PESQUISA COM CONTAGEM DE COMPARAÇÕES
    private void pesquisar(No no, String nome) {
        if (no == null) {
            System.out.println(" NAO");
            comparacoes++;
            return;
        }

        int cmp = nome.compareTo(no.game.getNome());
        comparacoes++;

        if (cmp == 0) {
            System.out.println(" SIM");
        } else if (cmp < 0) {
            System.out.print(" esq");
            pesquisar(no.esq, nome);
        } else {
            System.out.print(" dir");
            pesquisar(no.dir, nome);
        }
    }
}
// CLASSE PRINCIPAL
public class AVN { 

    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void main(String[] args) {
        long inicio = System.currentTimeMillis();
        ArvoreAlvinegra arvore = new ArvoreAlvinegra();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            //INSERÇÃO DA ARVORE
            String entrada = br.readLine();
            while (entrada != null && !isFim(entrada)) {
                try {
                    Game g = new Game();
                    g.ler(entrada);
                    if (g.getNome() != null) {
                        arvore.inserir(g);
                    }
                } catch (Exception e) {
                }
                entrada = br.readLine();
            }

            //PESQUISA NA ARVORE
            entrada = br.readLine();
            while (entrada != null && !isFim(entrada)) {
                arvore.pesquisar(entrada);
                entrada = br.readLine();
            }

            // GERAR LOG(IGUAL TP05)
            long fim = System.currentTimeMillis();
            long tempoExecucao = fim - inicio;
            String matricula = "885080"; 
            FileWriter logFile = new FileWriter(matricula + "_alvinegra.txt");
            logFile.write(matricula + "\t" + tempoExecucao + "\t" + arvore.comparacoes);
            logFile.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}