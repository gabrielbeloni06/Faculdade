import java.io.*;
import java.util.*;
// CLASSE GAME (AJUSTE DE ACORDO COM ENUNCIADO)
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

    // CALCULO DA CHAVE COMO PASSADO NO ENUNCIADO
    public int getChaveAuxiliar() {
        if (this.proprietarios == null || this.proprietarios.isEmpty()) return 0;
        String limpa = this.proprietarios.replace(",", "").trim();
        String[] partes = limpa.split(" .. ");
        
        long min = 0, max = 0;
        try {
            if (partes.length >= 1) min = Long.parseLong(partes[0]);
            if (partes.length >= 2) max = Long.parseLong(partes[1]);
        } catch (NumberFormatException e) {
            return 0;
        }

        long media = (min + max) / 2;
        return (int)(media % 15);
    }

    //METODO DE FORMATAR (IGUAL TP05)
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
// METODO DE FORMATAR DATA (IGUAL TP05)
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
    public void ler(String appID) throws Exception {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader("/tmp/games.csv"));
            String linha;
            br.readLine(); 
            while ((linha = br.readLine()) != null) {
                String[] base = linha.split(",");
                if (base.length > 0 && base[0].equals(appID)) {
                    String[] campos = quebrarLinhaCSVManual(linha);
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
        } catch (FileNotFoundException e) {
        } finally {
            if (br != null) br.close();
        }
    }
}

// ESTRUTURAS DE ARVORES

// CLASS NO DA SEGUNDA ARVORE
class No2 {
    public Game game;
    public No2 esq, dir;

    public No2(Game game) {
        this.game = game;
        this.esq = null;
        this.dir = null;
    }
}

//CLASS NO DA PRIMEIRA ARVORE
class No1 {
    public int chave;
    public No1 esq, dir;
    public No2 raizSecundaria;

    public No1(int chave) {
        this.chave = chave;
        this.esq = null;
        this.dir = null;
        this.raizSecundaria = null;
    }
}

// CLASS DA ARVORE DE ARVORE
class ArvoreDeArvore {
    private No1 raiz;
    public int comparacoes;

    public ArvoreDeArvore() {
        this.raiz = null;
        this.comparacoes = 0;
        int[] chaves = {7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14};
        for (int x : chaves) {
            this.inserirPrimeiraArvore(x);
        }
    }

    // INSERÇÃO DA PRIMEIRA ARVORE
    private void inserirPrimeiraArvore(int chave) {
        raiz = inserirNo1(raiz, chave);
    }

    private No1 inserirNo1(No1 i, int chave) {
        if (i == null) {
            i = new No1(chave);
        } else if (chave < i.chave) {
            i.esq = inserirNo1(i.esq, chave);
        } else if (chave > i.chave) {
            i.dir = inserirNo1(i.dir, chave);
        }
        return i;
    }

    //INSERÇÃO DO GAME
    public void inserir(Game g) {
        int chave = g.getChaveAuxiliar();
        inserirNaSecundaria(raiz, chave, g);
    }

    private void inserirNaSecundaria(No1 i, int chave, Game g) {
        if (i == null) return;
        if (chave == i.chave) {
            i.raizSecundaria = inserirNo2(i.raizSecundaria, g);
        } else if (chave < i.chave) {
            inserirNaSecundaria(i.esq, chave, g);
        } else {
            inserirNaSecundaria(i.dir, chave, g);
        }
    }
    //INSERÇÃO NA SEGUNDA ARVORE
    private No2 inserirNo2(No2 i, Game g) {
        if (i == null) {
            i = new No2(g);
        } else if (g.getNome().compareTo(i.game.getNome()) < 0) {
            i.esq = inserirNo2(i.esq, g);
        } else if (g.getNome().compareTo(i.game.getNome()) > 0) {
            i.dir = inserirNo2(i.dir, g);
        }
        return i;
    }

    //METODO DE PESQUISA
    public void pesquisar(String nome) {
        System.out.print("=> " + nome + " => raiz");
        boolean encontrou = pesquisarGlobal(raiz, nome);
        if (encontrou) {
            System.out.println(" SIM");
        } else {
            System.out.println(" NAO");
        }
    }

    // PESQUISA NAS DUAS ARVORES
    private boolean pesquisarGlobal(No1 i, String nome) {
        if (i == null) return false;
        if (pesquisarSecundaria(i.raizSecundaria, nome)) {
            return true;
        }
        System.out.print(" ESQ ");
        if (pesquisarGlobal(i.esq, nome)) return true;
        System.out.print(" DIR ");
        if (pesquisarGlobal(i.dir, nome)) return true;

        return false;
    }

    private boolean pesquisarSecundaria(No2 i, String nome) {
        if (i == null) return false;

        comparacoes++; // Contando comparações de nomes
        int cmp = nome.compareTo(i.game.getNome());

        if (cmp == 0) {
            return true;
        } else if (cmp < 0) {
            System.out.print(" esq ");
            return pesquisarSecundaria(i.esq, nome);
        } else {
            System.out.print(" dir ");
            return pesquisarSecundaria(i.dir, nome);
        }
    }
}

// CLASSE PRINCIPAL (MUDANÇA DO TP06 PARA USAR ARVORE DE ARVORE)
public class AA {
    
    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void main(String[] args) {
        long inicio = System.currentTimeMillis();
        ArvoreDeArvore arvore = new ArvoreDeArvore();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            //INSERÇÃO DA ARVORE
            String entrada = br.readLine();
            while (entrada != null && !isFim(entrada)) {
                Game g = new Game();
                g.ler(entrada);
                if (g.getNome() != null) {
                    arvore.inserir(g);
                }
                entrada = br.readLine();
            }
            //PESQUISA NA ARVORE
            entrada = br.readLine();
            while (entrada != null && !isFim(entrada)) {
                arvore.pesquisar(entrada);
                entrada = br.readLine();
            }

            //ARQUIVO DE LOG (IGUAL TP 06)
            long fim = System.currentTimeMillis();
            long tempoExecucao = fim - inicio;
            String matricula = "885080";
            FileWriter logFile = new FileWriter(matricula + "_arvoreArvore.txt");
            logFile.write(matricula + "\t" + tempoExecucao + "\t" + arvore.comparacoes);
            logFile.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}