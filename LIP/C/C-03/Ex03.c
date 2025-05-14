#include <stdio.h>
int procedimento(int valor) {
    int soma = 0;

    printf("Estou no procedimento!\n");

    for (int i = 1; i <= valor; i++) {
        soma += i;
    }
    printf("saindo do procedimento!\n");
    return soma;
}
int main() {
    int vezes, valor, resultado;
    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &vezes);
    for (int i = 1; i <= vezes; i++) {
        printf("Digite o %d valor:\n", i);
        scanf("%d", &valor);
        printf("Chamando o procedimento!\n");
        resultado = procedimento(valor);
        printf("Voltou do procedimento!\n");
        printf("Soma de 1 ate %d = %d\n", valor, resultado);
    }
    return 0;
}