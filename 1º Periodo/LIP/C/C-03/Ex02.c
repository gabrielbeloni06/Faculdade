#include <stdio.h>
void procedimento(int valor) {
    int soma = 0;
    printf("Estou no procedimento!\n");
    for (int i = 1; i <= valor; i++) {
        soma += i;
    }
    printf("Soma de 1 ate %d = %d\n", valor, soma);
    printf("saindo do procedimento!\n");
}
int main() {
    int vezes, valor;
    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &vezes);
    for (int i = 1; i <= vezes; i++) {
        printf("Digite o %d valor:\n", i);
        scanf("%d", &valor);
        printf("Chamando o procedimento!\n");
        procedimento(valor);
        printf("Voltou do procedimento!\n");
    }
    return 0;
}