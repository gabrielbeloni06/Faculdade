import java.io.*;
import java.util.Scanner;

public class TP05_heap {
    private static final String MATRICULA = "885080";
    private static long numeroComparacoes = 0;
    private static long numeroMovimentacoes = 0;

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
        if (s1 == null || s2 == null || s1.length() != s2.length()) return false;
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
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') val = val * 10 + (c - '0');
            else if (val > 0) break;
            else return 0;
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
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '.') {
                if (encontrouPonto) return 0.0f;
                encontrouPonto = true;
            } else if (c >= '0' && c <= '9') {
                int digito = c - '0';
                if (!encontrouPonto) valor = valor * 10.0f + digito;
                else {
                    divisorDecimal *= 10.0f;
                    valor += digito / divisorDecimal;
                }
            } else {
                 if (valor > 0 || encontrouPonto) break;
                 else return 0.0f;
            }
        }
        return valor;
    }
    //NO TP04 USEI UMA BIBLIOTECA PARA FAZER A LEITURA DA ENTRADA, MAS AQUI VOU FAZER MANUALMENTE
    private static int parseEntradaManualInt(String s) {
        if (s == null || s.length() == 0) return -1;
        int valor = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') valor = valor * 10 + (c - '0');
            else return -1;
        }
        return valor;
    }

    //CLASSE GAME (campos arrumados em relação ao TP4)
    static class Game {
        int id;
        String nome;
        String lancamento;
        String proprietarios;
        float preco;
        String idiomas;
        int metacritic;
        float nota;
        int conquistas;
        String publishers;
        String developers;
        String categorias;
        String generos;
        String tags;
        Game(String[] dados) {
            this.id = parseManualInt(dados[0]);
            this.nome = removAspas(dados[1]);
            this.lancamento = removEspaco(dados[2]);
            this.proprietarios = dados[3];
            this.preco = parseManualFloat(dados[4]);
            this.idiomas = dados[5];
            this.metacritic = parseManualInt(dados[6]);
            this.nota = parseManualFloat(dados[7]);
            this.conquistas = parseManualInt(dados[8]);
            this.publishers = dados[9];
            this.developers = dados[10];
            this.categorias = dados[11];
            this.generos = dados[12];
            this.tags = dados[13];
        }
    }

     //FUNÇÃO PARA FORMATAR DATA IGUAL AO TP4
     private static String formatarDataParaSaida(String dataOriginal) {
        if (dataOriginal == null || dataOriginal.length() < 3) return dataOriginal;

        String[] meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        String dataLimpa = removAspas(dataOriginal);

        String[] partes = new String[3];
        int countPartes = 0;
        String parteAtual = "";
        for (int i = 0; i < dataLimpa.length(); i++) {
            char c = dataLimpa.charAt(i);
            if (c == ' ') {
                if (parteAtual.length() > 0 && countPartes < 3) {
                    partes[countPartes++] = parteAtual;
                    parteAtual = "";
                }
                while (i + 1 < dataLimpa.length() && dataLimpa.charAt(i + 1) == ' ') {
                    i++;
                }
            } else {
                parteAtual += c;
            }
        }
        if (parteAtual.length() > 0 && countPartes < 3) {
            partes[countPartes++] = parteAtual;
        }
        if (countPartes >= 2) {
            String mesStr = partes[0];
            String diaStr = "?";
            String anoStr = "?";
            int mesInt = 0;
            for (int i = 0; i < meses.length; i++) {
                if (iguais(mesStr, meses[i])) {
                    mesInt = i + 1;
                    break;
                }
            }
            if (mesInt > 0) {
                 boolean temVirgula = false;
                 String parte2 = partes[1];
                 for(int i=0; i < parte2.length(); i++){
                     if(parte2.charAt(i) == ',') {
                         temVirgula = true;
                         break;
                     }
                 }
                 if (countPartes == 2 && !temVirgula) {
                     diaStr = "01";
                     anoStr = partes[1];
                 } else if (countPartes >= 2 && temVirgula) {
                     String diaComVirgula = partes[1];
                     String diaSemVirgula = "";
                     for(int i=0; i < diaComVirgula.length(); i++){
                         if(diaComVirgula.charAt(i) != ','){
                             diaSemVirgula += diaComVirgula.charAt(i);
                         }
                     }
                     diaStr = diaSemVirgula;
                     if (countPartes == 3) {
                        anoStr = partes[2];
                     } else {
                        anoStr = "?";
                     }
                 } else {
                     return dataOriginal;
                 }
                int diaInt = 0;
                boolean diaValido = true;
                if(diaStr.length() == 0 || diaStr.length() > 2) diaValido = false;
                for(int i=0; i<diaStr.length(); i++) {
                    char c = diaStr.charAt(i);
                    if(c >= '0' && c <= '9') {
                        diaInt = diaInt * 10 + (c - '0');
                    } else {
                        diaValido = false;
                        break;
                    }
                }
                if (diaInt < 1 || diaInt > 31) diaValido = false;
                if (diaValido) {
                     String diaF;
                     String mesF;
                     if (diaInt < 10) {
                         diaF = "0" + diaInt;
                     } else {
                         diaF = "" + diaInt;
                     }
                     if (mesInt < 10) {
                         mesF = "0" + mesInt;
                     } else {
                         mesF = "" + mesInt;
                     }
                     boolean anoValido = true;
                     if(anoStr.length() != 4 && !iguais(anoStr, "?")) anoValido = false;
                     if(anoValido && !iguais(anoStr, "?")) {
                         for(int i=0; i<anoStr.length(); i++){
                             if(anoStr.charAt(i) < '0' || anoStr.charAt(i) > '9'){
                                 anoValido = false;
                                 break;
                             }
                         }
                     }
                     if (anoValido) {
                        return diaF + "/" + mesF + "/" + anoStr;
                     } else {
                        return diaF + "/" + mesF + "/?";
                     }
                }
            }
        }
        return dataOriginal;
     }
        private static String formatListField(String raw) {
            if (raw == null) return "[]";
            String s = removEspaco(removAspas(raw));
            if (s.length() == 0) return "[]";
            boolean hadBrackets = false;
            if (s.startsWith("[") && s.endsWith("]")) {
                hadBrackets = true;
                s = s.substring(1, s.length() - 1);
            }
            String noSingle = "";
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c != '\'') noSingle += c;
            }
            String[] parts = noSingle.split(",");
            StringBuilder out = new StringBuilder();
            for (int i = 0; i < parts.length; i++) {
                String p = removEspaco(parts[i]);
                if (p.length() == 0) continue;
                if (out.length() > 0) out.append(", ");
                out.append(p);
            }
            String result = out.toString();
            return "[" + result + "]";
        }

    //FUNÇÃO PARA ANALISAR LINHA CSV
    public static void analisarLinhaCSV(String linha, String[] dados) {
        int indice = 0, inicio = 0;
        boolean aspas = false, colchetes = false;
        for (int i = 0; i < linha.length(); i++) {
            char c = linha.charAt(i);
            if (c == '"') aspas = !aspas;
            else if (c == '[') colchetes = true;
            else if (c == ']') colchetes = false;
            else if (c == ',' && !aspas && !colchetes) {
                String parte = "";
                for (int k = inicio; k < i; k++) parte += linha.charAt(k);
                dados[indice++] = parte;
                inicio = i + 1;
            }
        }
        String parteFim = "";
        for (int i = inicio; i < linha.length(); i++) parteFim += linha.charAt(i);
        dados[indice] = parteFim;
    }
    //FUNÇÃO PARA LER ARQUIVO (IGUAL O TP4)
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

    //HEAPSORT COM DIVISÃO EM 3 FUNÇÕES
    private static void swap(Game[] array, int i, int j) {
        Game temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        numeroMovimentacoes += 3;
    }

    private static boolean maior(Game a, Game b) {
        numeroComparacoes++;
        String[] propAParts = a.proprietarios.contains(" ") ? a.proprietarios.split(" ") : new String[]{a.proprietarios};
        String[] propBParts = b.proprietarios.contains(" ") ? b.proprietarios.split(" ") : new String[]{b.proprietarios};

        String propAStr = (propAParts.length > 0) ? propAParts[0] : "0";
        String propBStr = (propBParts.length > 0) ? propBParts[0] : "0";
        String numAStr = "";
        for(int i=0; i<propAStr.length(); i++) if(propAStr.charAt(i) != ',') numAStr += propAStr.charAt(i);
        String numBStr = "";
        for(int i=0; i<propBStr.length(); i++) if(propBStr.charAt(i) != ',') numBStr += propBStr.charAt(i);

        int ownersA = parseManualInt(numAStr);
        int ownersB = parseManualInt(numBStr);

        if (ownersA != ownersB) return ownersA > ownersB;
        numeroComparacoes++;
        return a.id > b.id;
    }


    private static void heap2(Game[] array, int n, int i) {
        int maiorIdx = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        if (esq < n) {
            if (maior(array[esq], array[maiorIdx])) {
                maiorIdx = esq;
            }
        }
        if (dir < n) {
            if (maior(array[dir], array[maiorIdx])) {
                 maiorIdx = dir;
            }
        }

        if (maiorIdx != i) {
            swap(array, i, maiorIdx);
            heap2(array, n, maiorIdx);
        }
    }
    private static void heapsort(Game[] array, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) heap2(array, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(array, 0, i);
            heap2(array, i, 0);
        }
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
            if (dados[0] != null && dados[0].length() > 0 && !iguais(dados[0], "\"\"")) {
                for (int j = 0; j < dados.length; j++) {
                     if (dados[j] == null) dados[j] = "";
                     dados[j] = removEspaco(dados[j]);
                }
                 if (parseManualInt(dados[0]) > 0) {
                    allGames[contadorAllGames++] = new Game(dados);
                 }
            }
        }


        Game[] selectedGames = new Game[500];
        int selectedGamesCount = 0;
        try (Scanner leitorEntrada = new Scanner(System.in)) {
            String entrada;
            while (!iguais((entrada = leitorEntrada.nextLine()), "FIM")) {
                int idProcurado = parseEntradaManualInt(entrada);
                for (int i = 0; i < contadorAllGames; i++) {
                     if (allGames[i] != null && allGames[i].id == idProcurado) {
                        selectedGames[selectedGamesCount++] = allGames[i];
                        break;
                    }
                }
            }
        }

        //CHAMADA DO HEAP
        long startTimeSort = System.currentTimeMillis();
        heapsort(selectedGames, selectedGamesCount);
        long endTimeSort = System.currentTimeMillis();
        for (int i = 0; i < selectedGamesCount; i++) {
            Game g = selectedGames[i];
            String dataFormatada = formatarDataParaSaida(g.lancamento);
            String idiomasFormatado = formatListField(g.idiomas);
            String publisherFinal = formatListField(g.publishers);
            String developerFinal = formatListField(g.developers);
            String categoriasFinal = formatListField(g.categorias);
            String generosFinal = formatListField(g.generos);
            String tagsFinal = formatListField(g.tags);
            System.out.printf(java.util.Locale.US, "=> %d ## %s ## %s ## %s ## %.2f ## %s ## %d ## %.1f ## %d ## %s ## %s ## %s ## %s ## %s ##\n",
                    g.id,
                    g.nome,
                    dataFormatada,
                    g.proprietarios,
                    g.preco,
                    idiomasFormatado,
                    g.metacritic,
                    g.nota,
                    g.conquistas,
                    publisherFinal,
                    developerFinal,
                    categoriasFinal,
                    generosFinal,
                    tagsFinal
            );
        }
        double tempoExecucaoSort = (endTimeSort - startTimeSort) / 1000.0;
        try (PrintWriter logWriter = new PrintWriter(new FileWriter(MATRICULA + "_heapsort.txt"))) {
            logWriter.printf(java.util.Locale.US, "%s\t%d\t%d\t%.3f\n", MATRICULA, numeroComparacoes, numeroMovimentacoes, tempoExecucaoSort);
        } catch (IOException e) {
        }
    }
}