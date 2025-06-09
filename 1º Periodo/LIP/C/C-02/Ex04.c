#include <stdio.h>
int main() {
    int numero;
    printf("Digite um numero:\n");
    scanf("%d", &numero);
    while (numero >= 0) {
        if (numero % 5 == 0 && numero % 3 == 0)
            printf("O numero %d e divisivel por 5 e 3 ao mesmo tempo\n", numero);
        else if (numero % 5 == 0)
            printf("O numero %d e divisivel por 5 mas nao por 3\n", numero);
        else if (numero % 3 == 0)
            printf("O numero %d e divisivel por 3 mas nao por 5\n", numero);
        else
            printf("O numero %d nao e divisivel nem por 5 nem por 3\n", numero);

        printf("Digite um numero(flag valor negativo):\n");
        scanf("%d", &numero);
    }
    return 0;
}