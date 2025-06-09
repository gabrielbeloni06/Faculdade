#include <stdio.h>
void verificarPrimo(int num) {
    int i, ehPrimo = 1;
    printf("Estou no procedimento!\n");
    if (num < 2) {
        ehPrimo = 0;
    } else {
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                ehPrimo = 0;
                break;
            }
        }
    }
    if (ehPrimo) {
        printf("Numero %d eh primo!\n", num);
    } else {
        printf("Numero %d nao eh primo!\n", num);
    }
    printf("saindo do procedimento!\n");
}
int main() {
    int qtd, i, valor;
    printf("Quantos numero voce deseja verificar?:\n");
    scanf("%d", &qtd);
    for (i = 1; i <= qtd; i++) {
        printf("Digite o %d numero a ser verificado:\n", i);
        scanf("%d", &valor);
        printf("Chamando o procedimento!\n");
        verificarPrimo(valor);
        printf("Voltou do procedimento!\n");
    }
    return 0;
}