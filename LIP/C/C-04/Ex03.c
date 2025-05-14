// Exercício 3 - Gabriel Egídio Santos Beloni
#include <stdio.h>
void saudarVisitante(char nome[]) {
    printf("Estou no procedimento!\n");
    printf("Ola,%s! Seja bem-vindo ao Reino!\n", nome);
    printf("saindo do procedimento!\n");
}
int main() {
    int qtd;
    char nomes[5][51] = {
        "", 
        "Jose", 
        "Maria Jose", 
        "Jose Maria", 
        "Marco Antonio e Silva Jardim"
    };
    printf("Quantos visitantes voce deseja?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %d nome:\n", i + 1);
        printf("Chamando o procedimento!\n");
        saudarVisitante(nomes[i]);
        printf("Voltou do procedimento!\n");
    }
    return 0;
}