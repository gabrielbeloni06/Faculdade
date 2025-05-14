#include <stdio.h>
int calcularFatorial(int valor) {
    int fatorial = 1;
    printf("Estou no procedimento!\n");
    for (int i = 1; i <= valor; i++) {
        fatorial *= i;
    }
    printf("saindo do procedimento!\n");
    return fatorial;
}
int main() {
    int vezes, valor, resultado;
    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &vezes);
    for (int i = 1; i <= vezes; i++) {
        printf("Digite o %d valor:\n", i);
        scanf("%d", &valor);

        printf("Chamando o procedimento!\n");
        resultado = calcularFatorial(valor);
        printf("Voltou do procedimento!\n");
        printf("O fatorial de %d = %d\n", valor, resultado);
    }
    return 0;
}