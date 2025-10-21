import java.io.*;
import java.util.Scanner;
public class TP04 {
    //MÉTODO PARA VERIFICAR ESPAÇOS EM BRANCO.
    private static boolean espVazio(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }
    //MÉTODO PARA REMOVER ASPAS DE UMA STRING, RETORNANDO UMA NOVA STRING SEM ASPAS
    public static String removAspas(String original) {
        if (original == null) return null;
        String resultado = "";
        for (int i = 0; i < original.length(); i++) {
            if (original.charAt(i) != '"') resultado += original.charAt(i);
        }
        return resultado;
    }
    //MÉTODO PARA REMOVER ESPAÇOS DESNECESSÁRIOS NO INÍCIO E NO FIM DA STRING
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
    //MÉTODO PARA COMPARAR DUAS STRINGS, RETORNANDO TRUE SE FOREM IGUAIS
    private static boolean iguais(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) return false;
        }
        return true;
    }
    //DEFINIÇÃO DA CLASSE GAME COM TODOS OS DADOS QUE VÃO SER USADOS E LIDOS DO CSV.
    static class Game {
        String id, nome, lancamento, proprietarios, preco, idiomas, metacritic, nota, conquistas, publishers, developers, categorias, generos, tags;
        Game(String[] dados) {
            id = dados[0];
            nome = dados[1];
            lancamento = dados[2];
            proprietarios = dados[3];
            preco = dados[4];
            idiomas = dados[5];
            metacritic = dados[6];
            nota = dados[7];
            conquistas = dados[8];
            publishers = dados[9];
            developers = dados[10];
            categorias = dados[11];
            generos = dados[12];
            tags = dados[13];
        }
        //MÉTODO PARA IMPRIMIR OS DADOS DO GAME NO FORMATO SOLICITADO
        public void imprimir() {
            //FORMATAÇÃO DOS CAMPOS PARA DEIXAR COM A SAÍDA NO FORMATO DO verde.
            System.out.print("=> ");
            System.out.print(removAspas(id) + " ## ");
            System.out.print(removAspas(nome) + " ## ");
            System.out.print(formatarData(lancamento) + " ## ");
            System.out.print(proprietarios + " ## ");
            System.out.print(preco + " ## ");
            System.out.print(formatarLista(idiomas) + " ## ");
            System.out.print(metacritic + " ## ");
            System.out.print(nota + ".0 ## ");
            System.out.print(conquistas + " ## ");
            System.out.print(formatarLista(publishers) + " ## ");
            System.out.print(formatarLista(developers) + " ## ");
            System.out.print(formatarLista(categorias) + " ## ");
            System.out.print(formatarLista(generos) + " ## ");
            System.out.print(formatarLista(tags) + " ##\n");
        }

        //MÉTODO PARA FORMATAR A DATA PARA DD/MM/YYYY
        private String formatarData(String data) {
            String[] meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
            if (data == null || data.length() == 0) return "";
            String dataFim = "";
            int inicio = 0;
            while (inicio < data.length() && espVazio(data.charAt(inicio))) {
                inicio++;
            }
            int fim = data.length() - 1;
            while (fim >= inicio && espVazio(data.charAt(fim))) {
                fim--;
            }
            for (int i = inicio; i <= fim; i++) {
                char c = data.charAt(i);
                if (c != '"') {
                    dataFim += c;
                }
            }
            if (dataFim.length() == 0) return "";
            String[] partes = new String[3];
            int countPartes = 0;
            String parteAtual = "";
            for (int i = 0; i < dataFim.length(); i++) {
                char c = dataFim.charAt(i);
                if (c == ' ') {
                    if (parteAtual.length() > 0 && countPartes < 3) {
                        partes[countPartes++] = parteAtual;
                        parteAtual = "";
                    }
                } else parteAtual += c;
            }
            if (parteAtual.length() > 0 && countPartes < 3) partes[countPartes++] = parteAtual;
            if (countPartes < 2) return data;
            String mes = partes[0];
            String diaStr = partes[1];
            String dia = "";
            for (int i = 0; i < diaStr.length(); i++) if (diaStr.charAt(i) != ',') dia += diaStr.charAt(i);
            String ano;
            if (countPartes > 2) ano = partes[2];
            else ano = "?";
            int numMes = 0;
            for (int i = 0; i < meses.length; i++) {
                if (iguais(mes, meses[i])) {
                    numMes = i + 1;
                    break;
                }
            }
            if (numMes == 0) return data;
            return String.format("%02d/%02d/%s", Integer.parseInt(dia), numMes, ano); //USEI INTEGER.PARSEINT PARA CONVERTER O TIPO STRING PARA INTEIRO, é possivel fazer com uma subtração também, caractere - 0;
        }
        //MÉTODO PARA FORMATAR LISTAS, REMOVENDO ASPAS, COLCHETES, E ADICIONANDO ESPAÇO APÓS VÍRGULA
        private String formatarLista(String campo) {
            if (campo == null) {
                return "[]";
            }
            int inicioConteudo = 0;
            while (inicioConteudo < campo.length() && espVazio(campo.charAt(inicioConteudo))) {
                inicioConteudo++;
            }
            int fimConteudo = campo.length() - 1;
            while (fimConteudo >= inicioConteudo && espVazio(campo.charAt(fimConteudo))) {
                fimConteudo--;
            }
            if (fimConteudo < inicioConteudo) {
                return "[]";
            }
            String resultado = "";
            for (int i = inicioConteudo; i <= fimConteudo; i++) {
                char c = campo.charAt(i);
                if (c == '"' || c == '[' || c == ']' || c == '\'') continue;
                if (c == ',') {
                    resultado += ", ";
                    while (i + 1 <= fimConteudo && espVazio(campo.charAt(i + 1))) {
                        i++;
                    }
                }else resultado += c;
            }
            return "[" + resultado + "]";
        }
    }
    //MÉTODO PARA ANALISAR LINHA DO CSV, SEPARANDO OS CAMPOS MESMO COM VÍRGULAS EM ASPAS E COLCHETES
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
    //MÉTODO PARA LER O ARQUIVO CSV E ARMAZENAR AS LINHAS EM UM ARRAY DE STRINGS
    public static int lerArquivo(String nomeArquivo, String[] linhas, int maxLinhas) throws IOException { //FOI NECESSÁRIO COLOCAR O THROWS IOEXCEPTION PARA LER O ARQUIVO CSV, NÃO CONSEGUI DE OUTRA FORMA.
        try (BufferedReader leitorArquivo = new BufferedReader(new FileReader(nomeArquivo))) { //USO DO TRY PARA GERENCIAR O BUFFEREDREADER, o buffered usado para ler o arquivo linha por linha.
            int count = 0;
            leitorArquivo.readLine(); // Ignora cabeçalho do arquivo csv, onde são dados exemplos.
            String linha;
            while ((linha = leitorArquivo.readLine()) != null && count < maxLinhas) {
                linhas[count++] = linha;
            }
            return count;
        }
    }
    //LÊ O CSV, PROCESSA OS DADOS E IMPRIME OS GAMES SOLICITADOS, ALÉM DE CHAMAR OS MÉTODOS DE TRATAMENTO DE STRINGS.
    public static void main(String[] args) throws IOException {
        String arquivoCsv = "/tmp/games.csv"; //CAMINHO DO ARQUIVO CSV
        String[] linhas = new String[4500];
        int totalDeGames = lerArquivo(arquivoCsv, linhas, 4500);
        Game[] games = new Game[4500];
        String[] ids = new String[4500];
        int contadorGames = 0;
        for (int i = 0; i < totalDeGames; i++) {
            String[] dados = new String[14];
            analisarLinhaCSV(linhas[i], dados);
            if (dados[0] != null && dados[0].length() > 0) {
                for (int j = 0; j < dados.length; j++) {
                    if (dados[j] != null) {
                        dados[j] = removEspaco(dados[j]);
                    }
                }
                games[contadorGames] = new Game(dados);
                ids[contadorGames] = removAspas(dados[0]);
                contadorGames++;
            }
        }
        try (Scanner leitorEntrada = new Scanner(System.in)) {
            String entrada;
            while (!iguais((entrada = leitorEntrada.nextLine()), "FIM")) {
                for (int i = 0; i < contadorGames; i++) {
                    if (iguais(ids[i], entrada)) {
                        games[i].imprimir();
                        break;
                    }
                }
            }
        }
    }
}