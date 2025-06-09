#include <stdio.h>
int main() {
    int numSeries, num, menorNumero;
    printf("Digite o numero de series:\n");
    scanf("%d", &numSeries);
    for (int serie = 1; serie <= numSeries; serie++) {
        int primeiroNumero = 1;
        printf("Digite o 1 numero da %d serie:\n", serie);
        scanf("%d", &num);
        if (num < 0) {
            printf("Nao existem numeros para essa serie!\n");
            continue;
        }
        menorNumero = num;
        int contador = 2;
        while (1) {
            printf("Digite o %d numero da %d serie (Flag valor negativo):\n", contador, serie);
            scanf("%d", &num);
            if (num < 0) {
                break;
            }
            if (num < menorNumero) {
                menorNumero = num;
            }
            contador++;
        }
        printf("O menor numero encontrado da %d serie = %d\n", serie, menorNumero);
    }
    return 0;
}