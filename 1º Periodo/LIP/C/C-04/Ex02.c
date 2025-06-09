// Exercicio 2 - Gabriel Egídio Santos Beloni
#include <stdio.h>
void verificarMaioridade(int idade) {
    printf("Estou no procedimento!\n");
    
    if (idade >= 18) {
        printf("Maior de idade\n");
    } else {
        printf("Menor de idade\n");
    }

    printf("saindo do procedimento!\n");
}
int main() {
    int qtd, idade;

    printf("Quantas idades voce deseja verificar?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %d valor:\n", i + 1);
        printf("Chamando o procedimento!\n");

        scanf("%d", &idade);
        verificarMaioridade(idade);

        printf("Voltou do procedimento!\n");
    }    
    return 0;
}