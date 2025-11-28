import java.io.*;
import java.util.*;
// CLASSE NO (Adaptada para Arvore)
class No {
    public Game game;
    public No esq, dir;

    public No(Game game) {
        this.game = game;
        this.esq = null;
        this.dir = null;
    }
}

// CLASSE GAME (igual TP05)
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
        this.lancamento = null;
        this.proprietarios = null;
        this.preco = 0.0f;
        this.idiomas = null;
        this.metacritic = 0;
        this.nota = 0.0f;
        this.conquistas = 0;
        this.publishers = null;
        this.developers = null;
        this.categorias = null;
        this.generos = null;
        this.tags = null;
    }

    public String getNome() {
        return this.nome;
    }
//METODO DE FORMATAÇÃO DE LISTA DE STRINGS
    private String formatarListaString(String s) {
        if (s == null) return null;
        
        String resultado = "";
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '\'') {
            } else if (c == ',') {
                resultado += ", "; 
                if (i + 1 < s.length() && s.charAt(i + 1) == ' ') {
                    i++; 
                }
            } else {
                resultado += c; 
            }
        }
        return resultado;
    }
//METODO DE FORMATAÇÃO DE DATA
    private String formatarData(String data) {
        if (data == null || data.isEmpty()) return "";
        String dia = "", mes = "", ano = "";
        String mesStr = "";
        
        String[] partes = data.split(" ");
        if (partes.length >= 3) { 
            mesStr = partes[0];
            dia = partes[1].substring(0, partes[1].length() - 1); 
            ano = partes[2];
        } else if (partes.length == 2) { 
            mesStr = partes[0];
            dia = "01";
            ano = partes[1];
        } else {
            return data;
        }

        if (dia.length() == 1) dia = "0" + dia;

        String mesNum = "";
        if (mesStr.equals("Jan")) mesNum = "01";
        else if (mesStr.equals("Feb")) mesNum = "02";
        else if (mesStr.equals("Mar")) mesNum = "03";
        else if (mesStr.equals("Apr")) mesNum = "04";
        else if (mesStr.equals("May")) mesNum = "05";
        else if (mesStr.equals("Jun")) mesNum = "06";
        else if (mesStr.equals("Jul")) mesNum = "07";
        else if (mesStr.equals("Aug")) mesNum = "08";
        else if (mesStr.equals("Sep")) mesNum = "09";
        else if (mesStr.equals("Oct")) mesNum = "10";
        else if (mesStr.equals("Nov")) mesNum = "11";
        else if (mesStr.equals("Dec")) mesNum = "12";
        else mesNum = "??";
        
        return dia + "/" + mesNum + "/" + ano;
    }
//METODO DE QUEBRA DE LINHA CSV (MANUAL)
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
        if (campoIndex < 14) {
            campos[campoIndex] = campoAtual;
        }

        return campos;
    }
//METODO DE LEITURA DO CSV
    public void ler(String appID) throws Exception {
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
        } catch (FileNotFoundException e) {
        } finally {
            if (br != null) br.close();
        }
    }
}

// CLASSE ARVORE BINARIA
class ArvoreBinaria {
    private No raiz;
    public int comparacoes;

    public ArvoreBinaria() {
        raiz = null;
        comparacoes = 0;
    }
    // METODO DE INSERÇÃO
    public void inserir(Game game) throws Exception {
        raiz = inserir(game, raiz);
    }

    private No inserir(Game game, No i) throws Exception {
        if (i == null) {
            i = new No(game);
        } else if (game.getNome().compareTo(i.game.getNome()) < 0) {
            i.esq = inserir(game, i.esq);
        } else if (game.getNome().compareTo(i.game.getNome()) > 0) {
            i.dir = inserir(game, i.dir);
        } else {
        }
        return i;
    }

    // METODO DE PESQUISA
    public void pesquisar(String nome) {
        System.out.print(nome + ": =>raiz");
        pesquisar(nome, raiz);
    }

    private void pesquisar(String nome, No i) {
        if (i == null) {
            System.out.println(" NAO");
            comparacoes++;
        } else {
            int cmp = nome.compareTo(i.game.getNome());
            comparacoes++;
            
            if (cmp == 0) {
                System.out.println(" SIM");
            } else if (cmp < 0) {
                System.out.print(" esq");
                pesquisar(nome, i.esq);
            } else {
                System.out.print(" dir");
                pesquisar(nome, i.dir);
            }
        }
    }
}

// CLASSE PRINCIPAL
public class ABP {
    
    public static boolean isFim(String s){
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void main(String[] args) {
        long inicio = System.currentTimeMillis();
        ArvoreBinaria arvore = new ArvoreBinaria();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String entrada = br.readLine();
            while (entrada != null && !isFim(entrada)) {
                Game g = new Game();
                g.ler(entrada);
                if (g.getNome() != null) {
                    arvore.inserir(g);
                }
                entrada = br.readLine();
            }
            entrada = br.readLine();
            while (entrada != null && !isFim(entrada)) {
                arvore.pesquisar(entrada);
                entrada = br.readLine();
            }
            //ARQUIVO DE LOG IGUAL AO TP05
            long fim = System.currentTimeMillis();
            long tempoExecucao = fim - inicio;
            String matricula = "885080"; 
            FileWriter logFile = new FileWriter(matricula + "_arvoreBinaria.txt");
            logFile.write(matricula + "\t" + tempoExecucao + "\t" + arvore.comparacoes);
            logFile.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}