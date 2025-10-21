#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//definição para o tamanho máximo dos dados usados, foi necessário definir, devido ao problema no privado do verde novamente.
const int MAX_LINHAS = 4500;
const int TAM_LINHA = 8192;
const int NUM_CAMPOS = 14;
//definição da struct Game com todos os dados que vão ser usados.
typedef struct {
    char *id, *nome, *lancamento, *proprietarios, *preco, *idiomas, *metacritic, *nota, *conquistas, *publishers, *developers, *categorias, *generos, *tags;
} Game;

bool espVazio(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
//MÉTODO PARA REMOVER ESPAÇOS DESNECESSÁRIOS NO INICIO E NO FIM DA STRING, RETORNANDO UMA NOVA STRING, SENDO USADO COM O METODO ABAIXO PARA DEIXAR UMA STRING LIMPA E APENAS COM OS DADOS NECESSÁRIOS.
char* removEspaco(const char* original) {
    if (original == NULL) return NULL;
    int inicio = 0;
    while (original[inicio] != '\0' && espVazio(original[inicio])) {
        inicio++;
    }
    int fim = strlen(original) - 1;
    while (fim >= inicio && espVazio(original[fim])) {
        fim--;
    }
    if (fim < inicio) {
        char* resultado = (char*)malloc(sizeof(char));
        resultado[0] = '\0';
        return resultado;
    }
    int tam = fim - inicio + 1;
    char* resultado = (char*)malloc((tam + 1) * sizeof(char));
    strncpy(resultado, original + inicio, tam);
    resultado[tam] = '\0';
    return resultado;
}
//METOODO PARA REMOVER ASPAS DE UMA STRING, RETORNANDO UMA NOVA STRING SEM ASPAS.
char* removAspas(const char* original) {
    if (original == NULL) return NULL;
    int tam = strlen(original);
    char* resultado = (char*)malloc((tam + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < tam; i++) {
        if (original[i] != '"') {
            resultado[j++] = original[i];
        }
    }
    resultado[j] = '\0';
    return resultado;
}
//ESTE MÉTODO COMPARA DUAS STRINGS, RETORNANDO TRUE SE FOREM IGUAIS E FALSE CASO CONTRÁRIO.
bool iguais(const char* s1, const char* s2) {
    if (s1 == NULL || s2 == NULL) return false;
    if (strlen(s1) != strlen(s2)) return false;
    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}
//ESTE MÉTODO FORMATA A LISTA, REMOVENDO ASPAS, COLCHETES E ADICIONANDO ESPAÇO APÓS A VÍRGULA, CASO A LISTA SEJA VAZIA RETORNA "[]", REMOVE TAMBÉM ESPAÇOS DESNECESSÁRIOS.
char* formatarLista(const char* campo) {
    if (campo == NULL) {
        return strdup("[]");
    }
    int tam = strlen(campo);
    char* temp = (char*)malloc((tam * 2 + 1) * sizeof(char)); 
    int j = 0;
    for (int i = 0; i < tam; i++) {
        char c = campo[i];
        if (c == '"' || c == '[' || c == ']' || c == '\'') continue;
        if (c == ',') {
            temp[j++] = ',';
            temp[j++] = ' ';
            while (i + 1 < tam && espVazio(campo[i + 1])) i++;
        } else {
            temp[j++] = c;
        }
    }
    temp[j] = '\0';
    char* resFinal = (char*)malloc((strlen(temp) + 3) * sizeof(char));
    sprintf(resFinal, "[%s]", temp);
    free(temp);
    return resFinal;
}
//ESTE METÓDO É USADO PARA CONVERTER A STRING PARA DIA/MES/ANO, É USADO OS NOMES EM INGLÊS COMO NO CSV, CASO A DATA ESTEJA COM PROBLEMA RETORNA A ORIGINAL, SE TUDO CERTO, RETORNA A DATA FORMATADA.
char* calcData(const char* data) {
    const char* meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    if (data == NULL || strlen(data) == 0) return strdup("");
    char* dataFim = removEspaco(data);
    if (strlen(dataFim) == 0) {
        free(dataFim);
        return strdup("");
    }
    char* partes[3];
    int countPartes=0;
    char* temp = strdup(dataFim);
    char* aux;
    char* sub = strtok_r(temp, " ", &aux); //
    while (sub != NULL && countPartes < 3) {
        partes[countPartes++] = sub;
        sub = strtok_r(NULL, " ", &aux);
    }
    if (countPartes < 2) {
        free(temp);
        return dataFim;
    }
    char* mes=partes[0];
    char* diaStr=partes[1];
    char dia[3]={0};
    int j=0;
    for (int i = 0; i < strlen(diaStr) && j < 2; i++) if (diaStr[i] != ',') dia[j++] = diaStr[i];
    char* ano;
    if (countPartes > 2) ano = partes[2];
    else ano = "?"; //CASO NÃO TENHA ANO SUBSTITUI POR QUALQUER COISA, foi necessário fazer isso, pois no privado do verde estava dando erro por causa disso.
    int numMes = 0;
    for (int i = 0; i < 12; i++) {
        if (iguais(mes, meses[i])) {
            numMes = i + 1;
            break;
        }
    }
    free(temp);
    free(dataFim);
    if (numMes == 0) return strdup(data);
    char* dataFormatada = (char*)malloc(12 * sizeof(char)); 
    //sprintf foi usado para formatar a string para a data correta, foi necessário usar com o atoi, pois estava dando erro no tipo da string e só resolveu assim.
    sprintf(dataFormatada, "%02d/%02d/%s", atoi(dia), numMes, ano); //atoi converte a string para inteiro, foi necessário pesquisar para usar, pois o verde estava brigando com a função.
    return dataFormatada;
}
void imprimir(Game* game) {
    //FORMATAÇÃO DOS CAMPOS PARA DEIXAR COM A SAIDA NO FORMATO DO VERDE
    char *idFim = removAspas(game->id);
    char *nomeFim = removAspas(game->nome);
    char *dataFim = calcData(game->lancamento);
    char *idiomaFim = formatarLista(game->idiomas);
    char *pubsFim = formatarLista(game->publishers);
    char *desenvFim = formatarLista(game->developers);
    char *categ = formatarLista(game->categorias);
    char *generosFim = formatarLista(game->generos);
    char *tagsFim = formatarLista(game->tags);
    //foi necessario fazer essa verificação de campos vazios, pois no privado do verde estava com algum campo no qual eu não conseguia encontrar, com algum error e o código dava 95% no publico e erro no privado, então foi necessário verificar todos os campos.
    char *idCorreto, *nomeCorreto, *dataCorreta, *propCorreto, *precoCorreto, *idiomaCorreto, *metaCorreta, *notaCorreto, *conqCorreto, *pubCorreto, *devCorreto, *categCorreta, *generosCorreto, *tagsCorreto;
    if (idFim != NULL) { idCorreto = idFim; } else { idCorreto = ""; }
    if (nomeFim != NULL) { nomeCorreto = nomeFim; } else { nomeCorreto = ""; }
    if (dataFim != NULL) { dataCorreta = dataFim; } else { dataCorreta = ""; }
    if (game->proprietarios != NULL) { propCorreto = game->proprietarios; } else { propCorreto = ""; }
    if (game->preco != NULL) { precoCorreto = game->preco; } else { precoCorreto = ""; }
    if (idiomaFim != NULL) { idiomaCorreto = idiomaFim; } else { idiomaCorreto = "[]"; }
    if (game->metacritic != NULL) { metaCorreta = game->metacritic; } else { metaCorreta = ""; }
    if (game->nota != NULL) { notaCorreto = game->nota; } else { notaCorreto = ""; }
    if (game->conquistas != NULL) { conqCorreto = game->conquistas; } else { conqCorreto = ""; }
    if (pubsFim != NULL) { pubCorreto = pubsFim; } else { pubCorreto = "[]"; }
    if (desenvFim != NULL) { devCorreto = desenvFim; } else { devCorreto = "[]"; }
    if (categ != NULL) { categCorreta = categ; } else { categCorreta = "[]"; }
    if (generosFim != NULL) { generosCorreto = generosFim; } else { generosCorreto = "[]"; }
    if (tagsFim != NULL) { tagsCorreto = tagsFim; } else { tagsCorreto = "[]"; }
    printf("=> %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s.0 ## %s ## %s ## %s ## %s ## %s ## %s ##\n",idCorreto, nomeCorreto, dataCorreta, propCorreto, precoCorreto, idiomaCorreto, metaCorreta, notaCorreto, conqCorreto, pubCorreto,devCorreto, categCorreta, generosCorreto, tagsCorreto);
    //free das strings alocadas.
    free(idFim); free(nomeFim); free(dataFim); free(idiomaFim);
    free(pubsFim); free(desenvFim); free(categ); free(generosFim);
    free(tagsFim);
}
//ESTE MÉTODO FUNCIONA PARA PEGAR OS CAMPOS DO CSV, MESMO COM VÍRGULAS DENTRO DE ASPAS E COLCHETES, E TAMBÉM TRATA OS CASOS, IGNORANDO AS VIRGULAS DENTRO DE ASPAS E COLCHETES.
//UTILIZEI ESTE STRDUP PARA PEGAR O ULTIMO CAMPO, JÁ QUE ELE NÃO TERMINA COM VÍRGULA, ASSIM ALOCANDO A MEMÓRIA NECESSÁRIA PARA ELE.
void analisarLinhaCSV(char* linha, char** dados) {
    int indice = 0;
    char* inicio = linha;
    bool aspas = false, colchetes = false;
    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '"') aspas = !aspas;
        else if (linha[i] == '[') colchetes = true;
        else if (linha[i] == ']') colchetes = false;
        if (linha[i] == ',' && !aspas && !colchetes && indice < NUM_CAMPOS - 1) {
            linha[i] = '\0'; 
            dados[indice++] = strdup(inicio); 
            inicio = &linha[i + 1];
        }
    }
    if (indice < NUM_CAMPOS) dados[indice] = strdup(inicio);
}
//ESTE METODO LÊ O ARQUIVO E ARMAZENA CADA LINHA EM UM ARRAY DE STRINGS, IGNORANDO A PRIMEIRA LINHA (CABEÇALHO) DO CSV, E TAMBÉM ALOCA A MEMÓRIA NECESSÁRIA PARA CADA LINHA, USANDO STRDUP
int lerArquivo(const char* nomeArquivo, char** linhas) {
    FILE* file = fopen(nomeArquivo, "r");
    if (file == NULL) return 0;
    char tamB[TAM_LINHA];
    int count = 0;
    fgets(tamB, TAM_LINHA, file); 
    while (fgets(tamB, TAM_LINHA, file) != NULL && count < MAX_LINHAS) {
        tamB[strcspn(tamB, "\n")] = 0; //ISSO AQUI PRECISEI USAR PRA REMOVER O \N NO FINAL DA LINHA, AI APROVEITEI A FUNÇAÕ DO STRING.H.
        linhas[count++] = strdup(tamB); 
    }
    fclose(file);
    return count;
}
int main() {
    char* arquivoCsv = "/tmp/games.csv"; //CAMINHO DO ARQUIVO CSV
    char** linhas = (char**)malloc(MAX_LINHAS * sizeof(char*)); //ALOCAÇÃO DE MEMÓRIA PARA AS LINHAS DO CSV
    int totalDeGames = lerArquivo(arquivoCsv, linhas); //LEITURA DO ARQUIVO CSV
    int tam_alloc; //VARIÁVEL PARA ALOCAÇÃO DO ARRAY DE GAMES
    if (totalDeGames > 0) tam_alloc = totalDeGames;
    else tam_alloc = 1;
    Game* games = (Game*)malloc(tam_alloc * sizeof(Game));
    char** ids = (char**)malloc(tam_alloc * sizeof(char*));
    int contadorGames = 0;
    for (int i = 0; i < totalDeGames; i++) {
        char* dados[NUM_CAMPOS]; //ARRAY PARA ARMAZENAR OS CAMPOS DE CADA LINHA
        for (int j = 0; j < NUM_CAMPOS; j++) dados[j] = NULL;
        analisarLinhaCSV(linhas[i], dados);
        //AQUI REPETE O PROCESSO DE REMOVER ESPAÇOS E ATRIBUIR OS VALORES A CADA CAMPO DE GAME
        if (dados[0] != NULL && strlen(dados[0]) > 0) {
            for (int j = 0; j < NUM_CAMPOS; j++) {
                char* temp = removEspaco(dados[j]);
                free(dados[j]); 
                dados[j] = temp;
            }
            games[contadorGames].id = dados[0];
            games[contadorGames].nome = dados[1];
            games[contadorGames].lancamento = dados[2];
            games[contadorGames].proprietarios = dados[3];
            games[contadorGames].preco = dados[4];
            games[contadorGames].idiomas = dados[5];
            games[contadorGames].metacritic = dados[6];
            games[contadorGames].nota = dados[7];
            games[contadorGames].conquistas = dados[8];
            games[contadorGames].publishers = dados[9];
            games[contadorGames].developers = dados[10];
            games[contadorGames].categorias = dados[11];
            games[contadorGames].generos = dados[12];
            games[contadorGames].tags = dados[13];
            ids[contadorGames] = removAspas(dados[0]);
            contadorGames++;
        } else {
            for (int j = 0; j < NUM_CAMPOS; j++) {
                if (dados[j] != NULL) free(dados[j]);
            }
        }
    }
    //LEITURA DO ID DO JOGO ATÉ ENCONTRAR FIM.
    char entrada[TAM_LINHA];
    while (fgets(entrada, TAM_LINHA, stdin) != NULL) {
        entrada[strcspn(entrada, "\n")] = 0; 
        if (iguais(entrada, "FIM")) {
            break;
        }
        for (int i = 0; i < contadorGames; i++) {
            if (iguais(ids[i], entrada)) {
                imprimir(&games[i]);
                break;
            }
        }
    }
    //LIBERAÇÃO DE MEMÓRIA DE TODOS OS MALLOC USADOS.
    for (int i = 0; i < totalDeGames; i++) free(linhas[i]);
    free(linhas);
    for (int i = 0; i < contadorGames; i++) {
        free(games[i].id);
        free(games[i].nome);
        free(games[i].lancamento);
        free(games[i].proprietarios);
        free(games[i].preco);
        free(games[i].idiomas);
        free(games[i].metacritic);
        free(games[i].nota);
        free(games[i].conquistas);
        free(games[i].publishers);
        free(games[i].developers);
        free(games[i].categorias);
        free(games[i].generos);
        free(games[i].tags);
        free(ids[i]);
    }
    free(games);
    free(ids);
    return 0;
}