#include <stdio.h>
int main() {
    int qtdSeries;
    printf("Digite o numero de series:\n");
    scanf("%d", &qtdSeries);
    for (int i = 1; i <= qtdSeries; i++) {
        int numero, contador = 0, soma = 0;
        int menor = 2147483647, maior = -2147483648;
        for (int j = 1;; j++) {
            if (j == 1)
                printf("Digite o 1 numero da %d serie:\n", i);
            else
                printf("Digite o %d numero da %d serie (Flag valor negativo):\n", j, i);
            scanf("%d", &numero);
            if (numero < 0)
                break;
            if (numero < menor)
                menor = numero;
            if (numero > maior)
                maior = numero;
            soma += numero;
            contador++;
        }
        printf("Resultado para a %d serie:\n", i);
        if (contador == 0) {
            printf("Nao existem numeros para essa serie!\n");
        } else {
            float media = (float)soma / contador;
            printf("O menor numero encontrado = %d\n", menor);
            printf("O maior numero encontrado = %d\n", maior);
            printf("A media = %.2f\n", media);
        }
    }
    return 0;
}