#include <stdio.h>
#include <ctype.h>
#include <string.h>

int contarLetras(char sentenca[]) {
    int i, contador = 0;

    printf("Estou na funcao!\n");

    for (i = 0; sentenca[i] != '\0'; i++) {
        if (isalpha(sentenca[i])) {
            contador++;
        }
    }

    printf("saindo da funcao!\n");

    return contador;
}

int main() {
    int quantidade, i;
    char sentenca[100];
    int totalLetras;

    printf("Quantas sentencas voce deseja contar as letras?:\n");
    scanf("%d", &quantidade);
    getchar();

    for (i = 1; i <= quantidade; i++) {
        printf("Digite a %d sentenca:\n", i);
        scanf(" %99[^\n]", sentenca);
        int len = strlen(sentenca);
        if (len > 0 && sentenca[len - 1] == 13) {
            sentenca[len - 1] = '\0';
        }

        printf("Chamando a funcao!\n");

        totalLetras = contarLetras(sentenca);

        printf("Voltou da funcao!\n");

        if (totalLetras == 1) {
            printf("A sentenca %s possui 1 letra\n", sentenca);
        } else {
            printf("A sentenca %s possui %d letras\n", sentenca, totalLetras);
        }
    }

}
