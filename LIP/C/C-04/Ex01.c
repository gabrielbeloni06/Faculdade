// Exercicio 1 - Gabriel Egídio Santos Beloni
#include <stdio.h>
void dobrarPoder(int poder) {
    printf("Estou no procedimento!\n");
    printf("O dobro de %d = %d\n", poder, poder * 2);
    printf("saindo do procedimento!\n");
}
int main() {
    int qtd, i, valor;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &qtd);

    for(i = 0; i < qtd; i++) {
        printf("Digite um valor:\n");
        scanf("%d", &valor);

        printf("Chamando o procedimento com o parametro %d!\n", valor);
        dobrarPoder(valor);
        printf("Voltou do procedimento!\n");
    }
    return 0;
}