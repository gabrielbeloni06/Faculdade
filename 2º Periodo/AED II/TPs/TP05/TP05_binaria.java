import java.io.*;
import java.util.Scanner;
public class TP05_binaria {
    private static final String MATRICULA = "885080";
    private static long numeroComparacoes = 0;
    private static boolean espVazio(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }
    //FUNÇÃO PARA REMOVER ASPAS (IGUAL O TP4)
    public static String removAspas(String original) {
        if (original == null) return null;
        String resultado = "";
        for (int i = 0; i < original.length(); i++) {
            if (original.charAt(i) != '"') resultado += original.charAt(i);
        }
        return resultado;
    }
    //FUNÇÃO PARA REMOVER ESPAÇOS (IGUAL O TP4)
    public static String removEspaco(String original) {
        if (original == null) return null;
        int inicio = 0;
        while (inicio < original.length() && espVazio(original.charAt(inicio))) {
            inicio++;
        }
        int fim = original.length() - 1;
        while (fim >= inicio && espVazio(original.charAt(fim))) {
            fim--;
        }
        if (fim < inicio) return "";
        String resultado = "";
        for (int i = inicio; i <= fim; i++) resultado += original.charAt(i);
        return resultado;
    }
    //METODO PARA COMPARAR DUAS STRINGS (IGUAL O TP4)
    private static boolean iguais(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) return false;
        }
        return true;
    }
    //NO TP04 USEI UMA BIBLIOTECA PARA FAZER A LEITURA DA ENTRADA, MAS AQUI VOU FAZER MANUALMENTE
    private static int parseManualInt(String s) {
        s = removAspas(s);
        if (s == null || s.length() == 0) return 0;

        int val = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c >= '0' && c <= '9') {
                val = val * 10 + (c - '0');
            } else {
                break;
            }
        }
        return val;
    }
    //NO TP04 USEI UMA BIBLIOTECA PARA FAZER A LEITURA DA ENTRADA, MAS AQUI VOU FAZER MANUALMENTE
    private static float parseManualFloat(String s) {
        s = removAspas(s);
        if (s == null || s.length() == 0) return 0.0f;
        float valor = 0.0f;
        float divisorDecimal = 1.0f;
        boolean encontrouPonto = false;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '.') {
                if (encontrouPonto) return 0.0f;
                encontrouPonto = true;
            } else if (c >= '0' && c <= '9') {
                int digito = c - '0';
                
                if (!encontrouPonto) {
                    valor = valor * 10.0f + digito;
                } else {
                    divisorDecimal = divisorDecimal * 10.0f;
                    valor = valor + (digito / divisorDecimal);
                }
            } else {
                return 0.0f;
            }
        }
        return valor;
    }
    //NO TP04 USEI UMA BIBLIOTECA PARA FAZER A LEITURA DA ENTRADA, MAS AQUI VOU FAZER MANUALMENTE
    private static int parseEntradaManualInt(String s) {
        if (s == null || s.length() == 0) return -1;

        int valor = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c >= '0' && c <= '9') {
                valor = valor * 10 + (c - '0');
            } else {
                return -1; 
            }
        }
        return valor;
    }
    //CLASSE GAME (CORRIGI OS CAMPOS ERRADOS FEITO COM STRING)
    static class Game {
        int id;
        String nome;
        String lancamento;
        String proprietarios;
        float preco;
        String idiomas;
        int metacritic;
        int nota;
        int conquistas;
        String publishers;
        String developers;
        String categorias;
        String generos;
        String tags;
        Game(String[] dados) {
            this.id = parseManualInt(dados[0]);
            this.nome = removAspas(dados[1]);
            this.lancamento = dados[2];
            this.proprietarios = dados[3];
            this.preco = parseManualFloat(dados[4]);
            this.idiomas = dados[5];
            this.metacritic = parseManualInt(dados[6]);
            this.nota = parseManualInt(dados[7]);
            this.conquistas = parseManualInt(dados[8]);
            this.publishers = dados[9];
            this.developers = dados[10];
            this.categorias = dados[11];
            this.generos = dados[12];
            this.tags = dados[13];
        }
    }
    //FUNÇÃO PARA ANALISAR LINHA CSV (IGUAL O TP04)
    public static void analisarLinhaCSV(String linha, String[] dados) {
        int indice=0;
        int inicio=0;
        boolean aspas = false, colchetes = false;
        for (int i = 0; i < linha.length(); i++) {
            char c = linha.charAt(i);
            if (c == '"') aspas = !aspas;
            else if (c == '[') colchetes = true;
            else if (c == ']') colchetes = false;
            else if (c == ',' && !aspas && !colchetes) {
                String parte = "";
                for (int k = inicio; k < i; k++) {
                    parte += linha.charAt(k);
                }
                dados[indice++] = parte;
                inicio = i + 1;
            }
        }
        String parteFim = "";
        for (int i = inicio; i < linha.length(); i++) parteFim += linha.charAt(i);
        dados[indice] = parteFim;
    }
    //FUNÇÃO PARA LER O ARQUIVO CSV (IGUAL O TP04)
    public static int lerArquivo(String nomeArquivo, String[] linhas, int maxLinhas) throws IOException { 
        try (BufferedReader leitorArquivo = new BufferedReader(new FileReader(nomeArquivo))) { 
            int count = 0;
            leitorArquivo.readLine();
            String linha;
            while ((linha = leitorArquivo.readLine()) != null && count < maxLinhas) {
                linhas[count++] = linha;
            }
            return count;
        }
    }
    //ORDENAÇÃO FEITA COM QUICKSORT
    private static void swap(Game[] array, int i, int j) {
        Game temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    private static void quicksort(Game[] array, int esq, int dir) {
        int i = esq, j = dir;
        String pivo = array[(esq + dir) / 2].nome; 
        while (i <= j) {
            while (array[i].nome.compareTo(pivo) < 0) i++;
            while (array[j].nome.compareTo(pivo) > 0) j--;
            
            if (i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if (esq < j) quicksort(array, esq, j);
        if (i < dir) quicksort(array, i, dir);
    }
    //METODO DA PESQUISA BINARIA IGUAL PEDE O ENUCIADO NO VERDE
    private static boolean pesquisaBinaria(Game[] array, int n, String nomeProcurado) {
        int esq = 0;
        int dir = n - 1;
        while (esq <= dir) {
            int meio = (esq + dir) / 2;
            numeroComparacoes++;
            int cmp = array[meio].nome.compareTo(nomeProcurado);
            if (cmp == 0) {
                return true;
            } else if (cmp < 0) {
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }
        return false;
    }
    public static void main(String[] args) throws IOException {
        long startTime = System.currentTimeMillis();
        String arquivoCsv = "/tmp/games.csv";
        String[] linhas = new String[4500];
        int totalDeGames = lerArquivo(arquivoCsv, linhas, 4500);
        Game[] allGames = new Game[4500];
        int contadorAllGames = 0;
        for (int i = 0; i < totalDeGames; i++) {
            String[] dados = new String[14];
            analisarLinhaCSV(linhas[i], dados);
            if (dados[0] != null && dados[0].length() > 0) {
                for (int j = 0; j < dados.length; j++) {
                    if (dados[j] != null) {
                        dados[j] = removEspaco(dados[j]);
                    }
                }
                allGames[contadorAllGames] = new Game(dados);
                contadorAllGames++;
            }
        }

        Game[] selectedGames = new Game[500];
        int selectedGamesCount = 0;
        try (Scanner leitorEntrada = new Scanner(System.in)) {
            String entrada;
            while (!iguais((entrada = leitorEntrada.nextLine()), "FIM")) {
                int idProcurado = parseEntradaManualInt(entrada); // Correção aqui
                for (int i = 0; i < contadorAllGames; i++) {
                    if (allGames[i].id == idProcurado) {
                        selectedGames[selectedGamesCount++] = allGames[i];
                        break;
                    }
                }
            }
            //ORDENAÇÃO COMO PEDIDO NO ENUNCIADO
            if (selectedGamesCount > 0) {
                quicksort(selectedGames, 0, selectedGamesCount - 1);
            }
            //VERIFICAÇÕES PARA EMITIR A SAÍDA PARA O VERDE
            numeroComparacoes = 0;
            while (!iguais((entrada = leitorEntrada.nextLine()), "FIM")) {
                if (pesquisaBinaria(selectedGames, selectedGamesCount, entrada)) {
                    System.out.println(" SIM");
                } else {
                    System.out.println(" NAO");
                }
            }
        }

        //ARQUIVO DE LOG
        //TIVE DIFICULDADE EM PEGAR O TEMPO EM DOUBLE, ENTÃO PEGUEI EM LONG E CONVERTI
        //PESQUISEI COMO CAPTURAR O TEMPO
        //PRECISEI PESQUISAR PARA RESOLVER A PARTE ABAIXO
        long endTime = System.currentTimeMillis();
        double timeInSeconds = (endTime - startTime) / 1000.0; 
        String logFilename = MATRICULA + "_binaria.txt";
        try (PrintWriter logWriter = new PrintWriter(new FileWriter(logFilename))) {
            logWriter.printf("%s\t%f\t%d\n", MATRICULA, timeInSeconds, numeroComparacoes);
        } catch (IOException e) {
        }
    }
}