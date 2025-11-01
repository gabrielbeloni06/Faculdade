#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

const int MAX_LINHAS = 4500;
const int TAM_LINHA = 8192;
const int NUM_CAMPOS = 14;
const char *MATRICULA = "885080";

//ESTRUTURA DO GAME (AJUSTE EM RELAÇÃO AO TP4)
typedef struct {
    int id;
    char *nome;
    char *lancamento;
    char *proprietarios;
    float preco;
    char *idiomas;
    int metacritic;
    float nota;
    int conquistas;
    char *publishers;
    char *developers;
    char *categorias;
    char *generos;
    char *tags;
} Game;

//FUNÇÃO PARA VERIFICAR ESPAÇOS (IGUAL O TP4)
bool espVazio(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

//FUNÇÃO PARA REMOVER ESPAÇOS (IGUAL O TP4)
char* removEspaco(const char* original) {
    if (original == NULL) return NULL;
    int inicio = 0;
    while (original[inicio] != '\0' && espVazio(original[inicio])) inicio++;
    int fim = strlen(original) - 1;
    while (fim >= inicio && espVazio(original[fim])) fim--;
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

//FUNÇÃO PARA REMOVER ASPAS (IGUAL O TP4)
char* removAspas(const char* original) {
    if (original == NULL) return NULL;
    int tam = strlen(original);
    char* resultado = (char*)malloc((tam + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < tam; i++) {
        if (original[i] != '"') resultado[j++] = original[i];
    }
    resultado[j] = '\0';
    return resultado;
}

//METODO PARA COMPARAR DUAS STRINGS (IGUAL O TP4)
bool iguais(const char* s1, const char* s2) {
    if (s1 == NULL || s2 == NULL) return false;
    if (strlen(s1) != strlen(s2)) return false;
    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

//FORMATAÇÃO DE LISTAS IGUAL AO TP4
char* formatarLista(const char* campo) {
    if (campo == NULL) return strdup("[]");
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

//FUNÇÃO PARA FORMATAR DATA IGUAL AO TP4
char* calcData(const char* dataOriginal) {
    if (dataOriginal == NULL || strlen(dataOriginal) < 3) return strdup(dataOriginal);

    const char* meses[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    char* dataLimpa = removAspas(dataOriginal);

    char* partes[3] = {NULL, NULL, NULL};
    int countPartes = 0;
    char buffer[20];
    int bufIndex = 0;

    for (int i = 0; i <= strlen(dataLimpa); i++) {
        char c = dataLimpa[i];
        if (c == ' ' || c == '\0') {
            if (bufIndex > 0 && countPartes < 3) {
                buffer[bufIndex] = '\0';
                partes[countPartes++] = strdup(buffer);
                bufIndex = 0;
            }
        } else buffer[bufIndex++] = c;
    }

    char* diaStr = "?";
    char* mesStr = partes[0];
    char* anoStr = "?";

    int mesInt = 0;
    for (int i = 0; i < 12; i++) {
        if (strcmp(mesStr, meses[i]) == 0) {
            mesInt = i + 1;
            break;
        }
    }

    if (mesInt > 0) {
        if (countPartes == 2) {
            diaStr = "01";
            anoStr = partes[1];
        } else if (countPartes >= 3) {
            char* diaTemp = partes[1];
            static char diaTempStr[3];
            int j = 0;
            for (int k = 0; k < strlen(diaTemp) && j < 2; k++) {
                if (diaTemp[k] != ',') diaTempStr[j++] = diaTemp[k];
            }
            diaTempStr[j] = '\0';
            diaStr = diaTempStr;
            anoStr = partes[2];
        }
    }

    int diaInt = atoi(diaStr);
    char diaF[3];
    if (diaInt < 10) sprintf(diaF, "0%d", diaInt);
    else sprintf(diaF, "%d", diaInt);

    char mesF[3];
    if (mesInt < 10) sprintf(mesF, "0%d", mesInt);
    else sprintf(mesF, "%d", mesInt);

    char* dataFinal = (char*)malloc(11 * sizeof(char));
    if (strcmp(anoStr, "?") == 0) sprintf(dataFinal, "%s/%s/?", diaF, mesF);
    else sprintf(dataFinal, "%s/%s/%s", diaF, mesF, anoStr);

    for(int i=0;i<countPartes;i++) if(partes[i]) free(partes[i]);
    free(dataLimpa);
    return dataFinal;
}

//FORMATAÇÃO DA SAIDA IGUAL AO TP 4
void imprimir(Game* game) {
    char *nomeFim = removAspas(game->nome);
    char *dataFim = calcData(game->lancamento);
    char *idiomaFim = formatarLista(game->idiomas);
    char *pubsFim = formatarLista(game->publishers);
    char *desenvFim = formatarLista(game->developers);
    char *categ = formatarLista(game->categorias);
    char *generosFim = formatarLista(game->generos);
    char *tagsFim = formatarLista(game->tags);
    printf("=> %d ## %s ## %s ## %s ## %.2f ## %s ## %d ## %.1f ## %d ## %s ## %s ## %s ## %s ## %s ##\n",
           game->id, nomeFim, dataFim, game->proprietarios, game->preco, idiomaFim,
           game->metacritic, game->nota, game->conquistas, pubsFim, desenvFim,
           categ, generosFim, tagsFim);
    free(nomeFim);
    free(dataFim);
    free(idiomaFim);
    free(pubsFim);
    free(desenvFim);
    free(categ);
    free(generosFim);
    free(tagsFim);
}

//ANALISAR LINHA CSV (IGUAL O TP4)
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

//LEITURA DO ARQUIVO CSV (IGUAL O TP4)
int lerArquivo(const char* nomeArquivo, char** linhas) {
    FILE* file = fopen(nomeArquivo, "r");
    if (file == NULL) return 0;
    char tamB[TAM_LINHA];
    int count = 0;
    fgets(tamB, TAM_LINHA, file);
    while (fgets(tamB, TAM_LINHA, file) != NULL && count < MAX_LINHAS) {
        tamB[strcspn(tamB, "\n")] = 0;
        linhas[count++] = strdup(tamB);
    }
    fclose(file);
    return count;
}

//SELECTION SORT APLICADO
void selectionSort(Game* array, int n, long *comparacoes, long *movimentacoes) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (strcmp(array[j].nome, array[menor].nome) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            Game temp = array[i];
            array[i] = array[menor];
            array[menor] = temp;
            (*movimentacoes)++;
        }
    }
}

//MAIN
int main() {
    char* arquivoCsv = "/tmp/games.csv";
    char** linhas = (char**)malloc(MAX_LINHAS * sizeof(char*));
    int totalDeGames = lerArquivo(arquivoCsv, linhas);
    int tam_alloc = totalDeGames > 0 ? totalDeGames : 1;
    Game* games = (Game*)malloc(tam_alloc * sizeof(Game));
    int contadorGames = 0;

    for (int i = 0; i < totalDeGames; i++) {
        char* dados[NUM_CAMPOS];
        for(int k = 0; k < NUM_CAMPOS; k++) dados[k] = NULL;
        analisarLinhaCSV(linhas[i], dados);
        if (dados[0] != NULL && strlen(dados[0]) > 0) {
            for (int j = 0; j < NUM_CAMPOS; j++) {
                char* temp = removEspaco(dados[j]);
                free(dados[j]);
                dados[j] = temp;
            }
            games[contadorGames].id = atoi(dados[0]);
            games[contadorGames].nome = dados[1];
            games[contadorGames].lancamento = dados[2];
            games[contadorGames].proprietarios = dados[3];
            games[contadorGames].preco = atof(dados[4]);
            games[contadorGames].idiomas = dados[5];
            games[contadorGames].metacritic = atoi(dados[6]);
            games[contadorGames].nota = atof(dados[7]);
            games[contadorGames].conquistas = atoi(dados[8]);
            games[contadorGames].publishers = dados[9];
            games[contadorGames].developers = dados[10];
            games[contadorGames].categorias = dados[11];
            games[contadorGames].generos = dados[12];
            games[contadorGames].tags = dados[13];
            contadorGames++;
        } else {
            for (int j = 0; j < NUM_CAMPOS; j++) if (dados[j]) free(dados[j]);
        }
    }

    char entrada[TAM_LINHA];
    Game* selecionados = (Game*)malloc(contadorGames * sizeof(Game));
    int contSelecionados = 0;
    while (fgets(entrada, TAM_LINHA, stdin) != NULL) {
        entrada[strcspn(entrada, "\n")] = 0;
        if (iguais(entrada, "FIM")) break;
        for (int i = 0; i < contadorGames; i++) {
            char tempId[20];
            sprintf(tempId, "%d", games[i].id);
            if (iguais(tempId, entrada)) {
                selecionados[contSelecionados++] = games[i];
                break;
            }
        }
    }

    long comparacoes = 0, movimentacoes = 0;
    clock_t start = clock();
    selectionSort(selecionados, contSelecionados, &comparacoes, &movimentacoes);
    clock_t end = clock();
    double tempoExec = (double)(end - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < contSelecionados; i++) imprimir(&selecionados[i]);

    FILE* log = fopen("885080_selecao.txt", "w");
    if (log) {
        fprintf(log, "%s\t%ld\t%ld\t%.3f\n", MATRICULA, comparacoes, movimentacoes, tempoExec);
        fclose(log);
    }

    for (int i = 0; i < totalDeGames; i++) free(linhas[i]);
    free(linhas);

    for (int i = 0; i < contadorGames; i++) {
        free(games[i].nome);
        free(games[i].lancamento);
        free(games[i].proprietarios);
        free(games[i].idiomas);
        free(games[i].publishers);
        free(games[i].developers);
        free(games[i].categorias);
        free(games[i].generos);
        free(games[i].tags);
    }
    free(games);
    free(selecionados);

    return 0;
}
