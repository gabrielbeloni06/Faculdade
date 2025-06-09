#include <stdio.h>
void procedimento() {
    int valor, soma = 0;
    printf("Estou no procedimento!\n");
    printf("Digite um valor:\n");
    scanf("%d", &valor);

    for (int i = 1; i <= valor; i++) {
        soma += i;
    }

    printf("Soma de 1 ate %d = %d\n", valor, soma);
    printf("saindo do procedimento!\n");
}
int main() {
    int vezes;
    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &vezes);

    for (int i = 0; i < vezes; i++) {
        printf("Chamando o procedimento!\n");
        procedimento();
        printf("Voltou do procedimento!\n");
    }
    return 0;
}