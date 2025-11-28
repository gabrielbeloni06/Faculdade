#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// DEFINIÇÕES DE LOG E CAMINHO DO CSV
const int TAM_LINHA = 8192;
const char *CSV_PATH = "/tmp/games.csv";
int comparacoes = 0;
// STRUCT GAME E FUNÇÕES (ATUALIZADAS DO TP05)
typedef struct Game {
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

// DUPLICA STRING (IGUAL TP05)
char *duplicarString(const char *s) {
    if (s == NULL) return NULL;
    char *d = (char *)malloc(strlen(s) + 1);
    strcpy(d, s);
    return d;
}
// FORMATA LISTA DE STRINGS (IGUAL TP05)
char* formatarListaString_C(const char* s) {
    if (s == NULL) return NULL;
    int maxLen = strlen(s) * 2 + 1;
    char* resultado = (char*) malloc(maxLen);
    char* dest = resultado;
    const char* src = s;
    while (*src) {
        if (*src == '\'') { src++; } 
        else if (*src == ',') {
            *dest++ = ','; *dest++ = ' '; src++;
            if (*src == ' ') src++;
        } else { *dest++ = *src++; }
    }
    *dest = '\0'; 
    return resultado;
}
//FORMATA DATA (IGUAL TP05)
char *formatarData(const char *data) {
    if (data == NULL) return duplicarString("");
    if (strlen(data) < 4) return duplicarString(data);
    return duplicarString(data);
}

Game *novoJogo() {
    Game *g = (Game *)malloc(sizeof(Game));
    g->id = 0; g->nome = NULL; g->lancamento = NULL; g->proprietarios = NULL;
    g->preco = 0.0f; g->idiomas = NULL; g->metacritic = 0; g->nota = 0.0f;
    g->conquistas = 0; g->publishers = NULL; g->developers = NULL;
    g->categorias = NULL; g->generos = NULL; g->tags = NULL;
    return g;
}
// FREE GAME (IGUAL TP05)
void liberarJogo(Game *g) {
    if (g) {
        free(g->nome); free(g->lancamento); free(g->proprietarios);
        free(g->idiomas); free(g->publishers); free(g->developers);
        free(g->categorias); free(g->generos); free(g->tags);
        free(g);
    }
}

// LEITURA DO CSV IGUAL TP05
char *proximoCampo(char **p) {
    char *linha = *p;
    char buffer[TAM_LINHA];
    char *b = buffer;
    if (*linha == '\0') return NULL;
    if (*linha == '"') {
        linha++;
        while (*linha != '\0') {
            if (*linha == '"') {
                if (*(linha + 1) == '"') { *b++ = '"'; linha += 2; }
                else { linha++; break; }
            } else { *b++ = *linha++; }
        }
    } else {
        while (*linha != '\0' && *linha != ',') { *b++ = *linha++; }
    }
    *b = '\0';
    if (*linha == ',') linha++;
    int len = strlen(buffer);
    if (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r')) buffer[len - 1] = '\0';
    if (len > 1 && (buffer[len - 2] == '\n' || buffer[len - 2] == '\r')) buffer[len - 2] = '\0';
    *p = linha;
    return duplicarString(buffer);
}
//METODO DE LEITURA (IGUAL TP05)
void lerJogo(Game *g, const char *appID) {
    FILE *file = fopen(CSV_PATH, "r");
    if (!file) return;
    char linha[TAM_LINHA];
    int appIDLen = strlen(appID);
    fgets(linha, TAM_LINHA, file);

    while (fgets(linha, TAM_LINHA, file)) {
        if (strncmp(linha, appID, appIDLen) == 0 && linha[appIDLen] == ',') {
            char *p = linha;
            char *campo;
            campo = proximoCampo(&p); if(campo) g->id = atoi(campo); free(campo);
            g->nome = proximoCampo(&p);
            char* lancamentoOriginal = proximoCampo(&p);
            g->proprietarios = proximoCampo(&p);
            campo = proximoCampo(&p); if(campo) g->preco = atof(campo); free(campo);
            char* tempIdiomas = proximoCampo(&p);
            campo = proximoCampo(&p); if(campo) g->metacritic = atoi(campo); free(campo);
            campo = proximoCampo(&p); if(campo) g->nota = atof(campo); free(campo);
            campo = proximoCampo(&p); if(campo) g->conquistas = atoi(campo); free(campo);
            g->publishers = proximoCampo(&p);
            g->developers = proximoCampo(&p);
            char* tempCategorias = proximoCampo(&p);
            char* tempGeneros = proximoCampo(&p);
            char* tempTags = proximoCampo(&p);

            g->lancamento = formatarData(lancamentoOriginal);
            free(lancamentoOriginal);
            g->idiomas = formatarListaString_C(tempIdiomas); free(tempIdiomas);
            g->categorias = formatarListaString_C(tempCategorias); free(tempCategorias);
            g->generos = formatarListaString_C(tempGeneros); free(tempGeneros);
            g->tags = formatarListaString_C(tempTags); free(tempTags);
            break;
        }
    }
    fclose(file);
}
// DEFINIÇÕES E METODOS DA ÁRVORE AVL

typedef struct No {
    Game *game;
    struct No *esq;
    struct No *dir;
    int altura;
} No;

int getAltura(No *no) {
    if (no == NULL) return 0;
    return no->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getFator(No *no) {
    if (no == NULL) return 0;
    return getAltura(no->esq) - getAltura(no->dir);
}
// CRIAR NOVO NÓ
No *novoNo(Game *g) {
    No *no = (No *)malloc(sizeof(No));
    no->game = g;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1;
    return no;
}

//METODO DE ROTAÇÃO PARA DIREITA

No *rotacionarDireita(No *y) {
    No *x = y->esq;
    No *T2 = x->dir;
    x->dir = y;
    y->esq = T2;
    y->altura = max(getAltura(y->esq), getAltura(y->dir)) + 1;
    x->altura = max(getAltura(x->esq), getAltura(x->dir)) + 1;

    return x;
}
// METODO DE ROTAÇÃO PARA ESQUERDA
No *rotacionarEsquerda(No *x) {
    No *y = x->dir;
    No *T2 = y->esq;
    y->esq = x;
    x->dir = T2;
    x->altura = max(getAltura(x->esq), getAltura(x->dir)) + 1;
    y->altura = max(getAltura(y->esq), getAltura(y->dir)) + 1;

    return y;
}

// METODO DE INSERÇÃO NA AVL

No *inserir(No *no, Game *g) {
    if (no == NULL) return novoNo(g);

    int cmp = strcmp(g->nome, no->game->nome);

    if (cmp < 0)
        no->esq = inserir(no->esq, g);
    else if (cmp > 0)
        no->dir = inserir(no->dir, g);
    else
        return no;
    no->altura = 1 + max(getAltura(no->esq), getAltura(no->dir));
    int balance = getFator(no);

    // ROTAÇÕES NECESSÁRIAS

    //ROTAÇÃO ESQUERDA-ESQUERDA
    if (balance > 1 && strcmp(g->nome, no->esq->game->nome) < 0)
        return rotacionarDireita(no);

    // ROTAÇÃO DIREITA-DIREITA
    if (balance < -1 && strcmp(g->nome, no->dir->game->nome) > 0)
        return rotacionarEsquerda(no);

    // ROTAÇÃO ESQUERDA-DIREITA
    if (balance > 1 && strcmp(g->nome, no->esq->game->nome) > 0) {
        no->esq = rotacionarEsquerda(no->esq);
        return rotacionarDireita(no);
    }

    //ROTAÇÃO DIREITA-ESQUERDA
    if (balance < -1 && strcmp(g->nome, no->dir->game->nome) < 0) {
        no->dir = rotacionarDireita(no->dir);
        return rotacionarEsquerda(no);
    }

    return no;
}

// METODO DE PESQUISA DA AVL

void pesquisarRecursivo(No *no, char *nome) {
    if (no == NULL) {
        printf(" NAO\n");
        comparacoes++;
        return;
    }

    int cmp = strcmp(nome, no->game->nome);
    comparacoes++;

    if (cmp == 0) {
        printf(" SIM\n");
    } else if (cmp < 0) {
        printf(" esq");
        pesquisarRecursivo(no->esq, nome);
    } else {
        printf(" dir");
        pesquisarRecursivo(no->dir, nome);
    }
}

void pesquisar(No *raiz, char *nome) {
    printf("%s: raiz", nome);
    pesquisarRecursivo(raiz, nome);
}
//FREE -> PARA LIBERAR A ARVORE
void liberarArvore(No *no) {
    if (no != NULL) {
        liberarArvore(no->esq);
        liberarArvore(no->dir);
        liberarJogo(no->game);
        free(no);
    }
}
// MAIN (MUDANÇAS PARA AVL)
int main() {
    clock_t inicio = clock();
    No *raiz = NULL;
    char buffer[1000];

    //LEITURA E INSERÇÃO NA AVL
    while (scanf("%s", buffer) == 1) {
        if (strcmp(buffer, "FIM") == 0) break;

        Game *g = novoJogo();
        lerJogo(g, buffer);
        
        if (g->nome != NULL) {
            raiz = inserir(raiz, g);
        } else {
            liberarJogo(g);
        }
    }
    fgets(buffer, sizeof(buffer), stdin); 

    // PESQUISA DA AVL
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        buffer[strcspn(buffer, "\r")] = 0;

        if (strcmp(buffer, "FIM") == 0) break;
        if (strlen(buffer) == 0) continue;

        pesquisar(raiz, buffer);
    }

    //METODO DE LOG (IGUAL TP05)
    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0;
    FILE *log = fopen("885080_avl.txt", "w"); 
    if (log) {
        fprintf(log, "885080\t%.4f\t%d\n", tempo, comparacoes);
        fclose(log);
    }

    liberarArvore(raiz);
    return 0;
}