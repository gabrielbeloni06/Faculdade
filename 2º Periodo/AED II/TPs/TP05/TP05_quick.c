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

long comparacoes = 0;
long movimentacoes = 0;

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
    while (original[inicio] != '\0' && espVazio(original[inicio])) {
        inicio++;
    }
    int fim = strlen(original) - 1;
    while (fim >= inicio && espVazio(original[fim])) {
        fim--;
    }
    if (fim < inicio) {
        char* resultado = (char*)malloc(sizeof(char));
        if (resultado == NULL) return NULL;
        resultado[0] = '\0';
        return resultado;
    }
    int tam = fim - inicio + 1;
    char* resultado = (char*)malloc((tam + 1) * sizeof(char));
    if (resultado == NULL) return NULL;
    strncpy(resultado, original + inicio, tam);
    resultado[tam] = '\0';
    return resultado;
}

//FUNÇÃO PARA REMOVER ASPAS (IGUAL O TP4)
char* removAspas(const char* original) {
    if (original == NULL) return NULL;
    int tam = strlen(original);
    char* resultado = (char*)malloc((tam + 1) * sizeof(char));
    if (resultado == NULL) return NULL;
    int j = 0;
    for (int i = 0; i < tam; i++) {
        if (original[i] != '"') {
            resultado[j++] = original[i];
        }
    }
    resultado[j] = '\0';
    char* final_resultado = (char*)realloc(resultado, (j + 1) * sizeof(char));
    if (final_resultado == NULL) {
        return resultado;
    } else {
        return final_resultado;
    }
}


//METODO PARA COMPARAR DUAS STRINGS (IGUAL O TP4)
bool iguais(const char* s1, const char* s2) {
    if (s1 == NULL || s2 == NULL) {
        if (s1 == s2) {
             return true;
        } else {
             return false;
        }
    }
    return strcmp(s1, s2) == 0;
}

//FORMATAÇÃO DE LISTAS IGUAL AO TP4 (Para adicionar colchetes e espaços)
char* formatarLista(const char* campo) {
    if (campo == NULL) return strdup("[]");
    char* campoLimpo = removEspaco(campo);
    if (campoLimpo == NULL) return strdup("[]");
    char* campoSemAspas = removAspas(campoLimpo);
    free(campoLimpo);
    if (campoSemAspas == NULL) return strdup("[]");
    int tamLimpo = strlen(campoSemAspas);
    char* conteudo = campoSemAspas;
    bool tinhaColchetesOriginais = false;
    if (tamLimpo >= 2 && campoSemAspas[0] == '[' && campoSemAspas[tamLimpo - 1] == ']') {
        conteudo = strndup(campoSemAspas + 1, tamLimpo - 2);
        free(campoSemAspas);
        if (conteudo == NULL) return strdup("[]");
        tinhaColchetesOriginais = true;
    }


    int tamConteudo = strlen(conteudo);
    int bufSize = tamConteudo * 2 + 3;
    char* temp = (char*)malloc(bufSize * sizeof(char));
    if (!temp) {
        if(tinhaColchetesOriginais) free(conteudo);
        return strdup("[]");
    }

    temp[0] = '[';
    int j = 1;
    bool ultimoFoiVirgula = false;

    for (int i = 0; i < tamConteudo; i++) {
        char c = conteudo[i];
        if (c == '\'') continue;

        if (c == ',') {
            while (j > 1 && temp[j-1] == ' ') j--;
            temp[j++] = ',';
            temp[j++] = ' ';
            ultimoFoiVirgula = true;
            while (i + 1 < tamConteudo && espVazio(conteudo[i + 1])) i++;
        } else if (espVazio(c)) {
             if (!ultimoFoiVirgula && j > 1 && temp[j-1] != ' ') {
                 temp[j++] = ' ';
             }
        } else {
            temp[j++] = c;
            ultimoFoiVirgula = false;
        }

        if (j >= bufSize - 2) {
             bufSize *= 2;
             char* newTemp = (char*)realloc(temp, bufSize * sizeof(char));
             if (!newTemp) {
                 free(temp);
                 if(tinhaColchetesOriginais) free(conteudo);
                 return strdup("[]");
             }
             temp = newTemp;
        }
    }
     while (j > 1 && temp[j-1] == ' ') j--;
    temp[j++] = ']';
    temp[j] = '\0';
    if (tinhaColchetesOriginais) free(conteudo);
    else free(campoSemAspas);
    char* resFinal = (char*)realloc(temp, (j + 1) * sizeof(char));
    if (!resFinal) {
        return temp;
    } else {
        return resFinal;
    }
}

//FORMATAÇÃO DA DATA PARA QUICKSORT E IMPRESSÃO (dd/MM/yyyy)
bool parseDataFormatada(const char *dataOriginal, int *ano, int *mes, int *dia) {
    *ano = 0; *mes = 0; *dia = 0;
    if (dataOriginal == NULL || strlen(dataOriginal) < 3) return false;

    char dataLimpa[100];
    int k = 0;
    for(int i=0; dataOriginal[i] != '\0' && k < 99; i++){
        if(dataOriginal[i] != '"') dataLimpa[k++] = dataOriginal[i];
    }
    dataLimpa[k] = '\0';

    if (strlen(dataLimpa) == 10 && dataLimpa[4] == '-' && dataLimpa[7] == '-') {
        if (sscanf(dataLimpa, "%d-%d-%d", ano, mes, dia) == 3) {
             if (*mes >= 1 && *mes <= 12 && *dia >= 1 && *dia <= 31 && *ano >= 1000) return true;
        }
    }

    char mesStr[10] = {0};
    int diaTemp = 0;
    int anoTemp = 0;
    int parts = sscanf(dataLimpa, "%3s %d, %d", mesStr, &diaTemp, &anoTemp);

    if (parts >= 2) {
        const char *meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < 12; i++) {
            if (iguais(mesStr, meses[i])) {
                *mes = i + 1;
                break;
            }
        }
        if (*mes > 0) {
            if (parts == 3) {
                *dia = diaTemp;
                *ano = anoTemp;
            } else {
                 if (diaTemp > 1000) {
                    *dia = 1;
                    *ano = diaTemp;
                 } else {
                     *dia = diaTemp;
                     char* commaPos = strchr(dataLimpa, ',');
                     if (commaPos != NULL && strlen(commaPos + 1) >= 4) {
                         bool anoOk = true;
                         for(int anoi = 0; anoi < 4; anoi++) {
                            if (!isdigit(*(commaPos + 1 + anoi))) {
                                anoOk = false;
                                break;
                            }
                         }
                         if (anoOk) sscanf(commaPos + 1, "%d", &anoTemp);
                         else anoTemp = 0;
                     } else {
                         anoTemp = 0;
                     }
                    *ano = anoTemp;
                 }
            }
             if (*dia >= 1 && *dia <= 31 && *ano >= 0) return true;
        }
    }
     *ano = 0; *mes = 0; *dia = 0;
    return false;
}

//METODO DE COMPARAÇÃO PARA AJUSTAR O QUICKSORT
int comparar(const void* a, const void* b) {
    comparacoes++;
    Game* jogoA = (Game*)a;
    Game* jogoB = (Game*)b;

    int anoA, mesA, diaA, anoB, mesB, diaB;
    bool parseadoA = parseDataFormatada(jogoA->lancamento, &anoA, &mesA, &diaA);
    bool parseadoB = parseDataFormatada(jogoB->lancamento, &anoB, &mesB, &diaB);

    if (parseadoA && !parseadoB) return -1;
    if (!parseadoA && parseadoB) return 1;

    if (parseadoA && parseadoB) {
        if (anoA != anoB) return anoA - anoB;
        if (mesA != mesB) return mesA - mesB;
        if (diaA != diaB) return diaA - diaB;
        comparacoes++;
        return jogoA->id - jogoB->id;
    } else {
        const char* lancA;
        if (jogoA->lancamento) {
            lancA = jogoA->lancamento;
        } else {
            lancA = "";
        }
        const char* lancB;
         if (jogoB->lancamento) {
            lancB = jogoB->lancamento;
        } else {
            lancB = "";
        }

        int dateCmp = strcmp(lancA, lancB);
        if (dateCmp != 0) return dateCmp;
        comparacoes++;
        return jogoA->id - jogoB->id;
    }
}

//FORMATAÇÃO DA SAIDA IGUAL AO TP 4
void imprimir(Game* game) {
    char *nomeFim = removAspas(game->nome);
    char dataFormatadaStr[11];
    int y, m, d;
    if (parseDataFormatada(game->lancamento, &y, &m, &d) && y > 0) {
        sprintf(dataFormatadaStr, "%02d/%02d/%d", d, m, y);
    } else {
        const char* lancOriginal;
        if (game->lancamento) {
            lancOriginal = game->lancamento;
        } else {
            lancOriginal = "?";
        }
        strncpy(dataFormatadaStr, lancOriginal, 10);
        dataFormatadaStr[10] = '\0';
    }

    char *idiomasFim = formatarLista(game->idiomas);
    char *pubsFim = formatarLista(game->publishers);
    char *devsFim = formatarLista(game->developers);
    char *catsFim = formatarLista(game->categorias);
    char *gensFim = formatarLista(game->generos);
    char *tagsFim = formatarLista(game->tags);
    char* nomePrint;
    if (nomeFim) nomePrint = nomeFim; else nomePrint = "";

    char* propPrint;
    if (game->proprietarios) propPrint = game->proprietarios; else propPrint = "";

    char* idiomasPrint;
    if (idiomasFim) idiomasPrint = idiomasFim; else idiomasPrint = "[]";

    char* pubsPrint;
     if (pubsFim) pubsPrint = pubsFim; else pubsPrint = "[]";

    char* devsPrint;
     if (devsFim) devsPrint = devsFim; else devsPrint = "[]";

    char* catsPrint;
     if (catsFim) catsPrint = catsFim; else catsPrint = "[]";

    char* gensPrint;
     if (gensFim) gensPrint = gensFim; else gensPrint = "[]";

    char* tagsPrint;
     if (tagsFim) tagsPrint = tagsFim; else tagsPrint = "[]";


    printf("=> %d ## %s ## %s ## %s ## %.2f ## %s ## %d ## %.1f ## %d ## %s ## %s ## %s ## %s ## %s ##\n",
           game->id,
           nomePrint,
           dataFormatadaStr,
           propPrint,
           game->preco,
           idiomasPrint,
           game->metacritic,
           game->nota,
           game->conquistas,
           pubsPrint,
           devsPrint,
           catsPrint,
           gensPrint,
           tagsPrint
    );

    free(nomeFim);
    free(idiomasFim);
    free(pubsFim);
    free(devsFim);
    free(catsFim);
    free(gensFim);
    free(tagsFim);
}

//ANALISAR LINHA CSV (IGUAL O TP4)
void analisarLinhaCSV(char* linha, char** dados) {
    for(int k=0; k<NUM_CAMPOS; k++) dados[k] = NULL;
    int indice = 0;
    char* inicio = linha;
    bool aspas = false, colchetes = false;
    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '"') aspas = !aspas;
        else if (linha[i] == '[') colchetes = true;
        else if (linha[i] == ']') colchetes = false;

        if (linha[i] == ',' && !aspas && !colchetes && indice < NUM_CAMPOS - 1) {
            linha[i] = '\0';
            dados[indice] = strdup(inicio);
            if (dados[indice] == NULL) {return; }
            indice++;
            inicio = &linha[i + 1];
        }
    }
    if (indice < NUM_CAMPOS) {
        dados[indice] = strdup(inicio);
         if (dados[indice] == NULL) { return; }
    }
    for(int k = indice + 1; k < NUM_CAMPOS; k++) {
        dados[k] = NULL;
    }
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
        tamB[strcspn(tamB, "\r")] = 0;
        if (strlen(tamB) > 0) {
             linhas[count] = strdup(tamB);
             if (linhas[count] == NULL) {
                 fclose(file);
                 return count;
             }
             count++;
        }
    }
    fclose(file);
    return count;
}
// QUICKSORT IMPLEMENTADO
void swap(Game* array, int i, int j) {
    movimentacoes += 3;
    Game temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void quicksortRec(Game* array, int esq, int dir) {
    if (esq >= dir) return;

    int i = esq, j = dir;
    Game pivo = array[(esq + dir) / 2];

    while (i <= j) {
        while (comparar(&array[i], &pivo) < 0) {
            i++;
        }
        while (comparar(&array[j], &pivo) > 0) {
            j--;
        }
        if (i <= j) {
            swap(array, i, j);
            i++;
            j--;
        }
    }
    quicksortRec(array, esq, j);
    quicksortRec(array, i, dir);
}

void quicksort(Game* array, int n) {
    if (n > 1) {
        quicksortRec(array, 0, n - 1);
    }
}


//FORMATAÇÃO DA SAIDA IGUAL AO TP 4 COM METODOS PARA LIBERAR A MEMORIA
int main() {
    char* arquivoCsv = "/tmp/games.csv";
    char** linhas = (char**)malloc(MAX_LINHAS * sizeof(char*));
    if (linhas == NULL) return 1;
    int totalDeGames = lerArquivo(arquivoCsv, linhas);
    int tam_alloc;
    if (totalDeGames > 0) {
        tam_alloc = totalDeGames;
    } else {
        tam_alloc = 1;
    }

    Game* games = (Game*)malloc(tam_alloc * sizeof(Game));
    if (games == NULL) {
        for (int i = 0; i < totalDeGames; i++) if(linhas[i]) free(linhas[i]);
        free(linhas);
        return 1;
    }
    int contadorGames = 0;

    for (int i = 0; i < totalDeGames; i++) {
        char* dados[NUM_CAMPOS];
        if (linhas[i] == NULL) continue;
        analisarLinhaCSV(linhas[i], dados);

        if (dados[0] != NULL && strlen(dados[0]) > 0 && !iguais(dados[0], "\"\"")) {
            char* cleaned_fields[NUM_CAMPOS];
            bool ok_to_add = true;

            for (int j = 0; j < NUM_CAMPOS; j++) {
                if (dados[j] == NULL) dados[j] = strdup("");
                 cleaned_fields[j] = removEspaco(dados[j]);
                 free(dados[j]);
                 if (cleaned_fields[j] == NULL) {
                     cleaned_fields[j] = strdup("");
                 }
            }
            int current_id;
            if (cleaned_fields[0]) {
                current_id = atoi(cleaned_fields[0]);
            } else {
                current_id = 0;
            }
            games[contadorGames].id = current_id;

            if (games[contadorGames].id > 0) {
                games[contadorGames].nome = cleaned_fields[1];
                games[contadorGames].lancamento = cleaned_fields[2];
                games[contadorGames].proprietarios = cleaned_fields[3];
                float current_price;
                if (cleaned_fields[4]) {
                    current_price = atof(cleaned_fields[4]);
                } else {
                    current_price = 0.0;
                }
                games[contadorGames].preco = current_price;
                games[contadorGames].idiomas = cleaned_fields[5];
                int current_metacritic;
                 if (cleaned_fields[6]) {
                    current_metacritic = atoi(cleaned_fields[6]);
                } else {
                    current_metacritic = 0;
                }
                games[contadorGames].metacritic = current_metacritic;
                 float current_nota;
                 if (cleaned_fields[7]) {
                    current_nota = atof(cleaned_fields[7]);
                } else {
                    current_nota = 0.0;
                }
                games[contadorGames].nota = current_nota;
                int current_conquistas;
                if (cleaned_fields[8]) {
                    current_conquistas = atoi(cleaned_fields[8]);
                } else {
                    current_conquistas = 0;
                }
                games[contadorGames].conquistas = current_conquistas;
                games[contadorGames].publishers = cleaned_fields[9];
                games[contadorGames].developers = cleaned_fields[10];
                games[contadorGames].categorias = cleaned_fields[11];
                games[contadorGames].generos = cleaned_fields[12];
                games[contadorGames].tags = cleaned_fields[13];
                free(cleaned_fields[0]);
                contadorGames++;
            } else {
                 ok_to_add = false;
            }

             if (!ok_to_add) {
                 for (int j = 0; j < NUM_CAMPOS; j++) free(cleaned_fields[j]);
             }
        } else {
             for (int j = 0; j < NUM_CAMPOS; j++) if (dados[j]) free(dados[j]);
        }
        free(linhas[i]);
    }
    free(linhas);
    Game* temp_games = (Game*)realloc(games, contadorGames * sizeof(Game));
     if (temp_games != NULL) {
        games = temp_games;
     } else if (contadorGames == 0) {
        if (games != NULL && tam_alloc > 0) free(games);
        games = NULL;
     }


    char entrada[TAM_LINHA];
    Game* selecionados = (Game*)malloc(contadorGames * sizeof(Game));
    if (selecionados == NULL) {
         for (int i = 0; i < contadorGames; i++) {
            if(games[i].nome) free(games[i].nome); if(games[i].lancamento) free(games[i].lancamento);
            if(games[i].proprietarios) free(games[i].proprietarios); if(games[i].idiomas) free(games[i].idiomas);
            if(games[i].publishers) free(games[i].publishers); if(games[i].developers) free(games[i].developers);
            if(games[i].categorias) free(games[i].categorias); if(games[i].generos) free(games[i].generos); if(games[i].tags) free(games[i].tags);
        }
        free(games);
        return 1;
    }
    int contSelecionados = 0;

    while (fgets(entrada, TAM_LINHA, stdin) != NULL) {
        entrada[strcspn(entrada, "\n")] = 0;
        if (iguais(entrada, "FIM")) break;
        int idProcurado = atoi(entrada);
        if (idProcurado <= 0) continue;

        for (int i = 0; i < contadorGames; i++) {
            if (games[i].id == idProcurado) {
                selecionados[contSelecionados++] = games[i];
                break;
            }
        }
    }
    //TIVE QUE PESQUISAR COMO FAZER TAMBÉM POIS O VERDE ESTAVA BRIGANDO COM UM ERRO DE ALOCACAO
     Game* temp_selecionados = (Game*)realloc(selecionados, contSelecionados * sizeof(Game));
      if (temp_selecionados != NULL) {
         selecionados = temp_selecionados;
      } else if (contSelecionados == 0) {
         if (selecionados != NULL) free(selecionados);
         selecionados = NULL;
      }


    //SISTEMA DO LOG (PESQUISADO)
    comparacoes = 0;
    movimentacoes = 0;
    clock_t start = clock();
    quicksort(selecionados, contSelecionados);
    clock_t end = clock();
    double tempoExec = (double)(end - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < contSelecionados; i++) {
        imprimir(&selecionados[i]);
    }

    char logFilename[50];
    sprintf(logFilename, "%s_quicksort.txt", MATRICULA);
    FILE* log = fopen(logFilename, "w");
    if (log) {
        fprintf(log, "%s\t%ld\t%ld\t%.3f\n", MATRICULA, comparacoes, movimentacoes, tempoExec);
        fclose(log);
    }

    //LIBERAÇÃO DE MEMÓRIA IGUAL AO TP4
    for (int i = 0; i < contadorGames; i++) {
        if(games[i].nome) free(games[i].nome);
        if(games[i].lancamento) free(games[i].lancamento);
        if(games[i].proprietarios) free(games[i].proprietarios);
        if(games[i].idiomas) free(games[i].idiomas);
        if(games[i].publishers) free(games[i].publishers);
        if(games[i].developers) free(games[i].developers);
        if(games[i].categorias) free(games[i].categorias);
        if(games[i].generos) free(games[i].generos);
        if(games[i].tags) free(games[i].tags);
    }
    free(games);
    if (selecionados != NULL) {
        free(selecionados);
    }
    return 0;
}