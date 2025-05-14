#include <stdio.h>
int main() {
    int numeroEscolhido;
    int primeiraVez = 1;
    while (1) {
        if (primeiraVez) {
            printf("Pense em um numero de 1 a 1023\n");
            primeiraVez = 0;
        } else {
            printf("Pense em um numero de 1 a 1023(flag valor <1)\n");
        }
        printf("Neste caso para testar o programa me diga o numero que voce escolheu:\n");
        scanf("%d", &numeroEscolhido);
        if (numeroEscolhido < 1) break;
        int tentativas = 0;
        int inicio = 1, fim = 1023;
        int palpite;
        while (inicio <= fim) {
            tentativas++;
            palpite = (inicio + fim) / 2;
            printf("O numerio >,< ou = %d\n", palpite);
            if (numeroEscolhido < palpite) {
                fim = palpite - 1;
            } else if (numeroEscolhido > palpite) {
                inicio = palpite + 1;
            } else {
                break;
            }
        }
        printf("Advinhei o numero %d em %d tentativas!\n", numeroEscolhido, tentativas);
    }
    return 0;
}