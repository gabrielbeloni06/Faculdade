// Exercicio 5 - Gabriel Egídio Santos Beloni
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int contarLetras(char frase[]) {
    printf("Estou na funcao!\n");
    int count = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        if ((frase[i] >= 'A' && frase[i] <= 'Z') || (frase[i] >= 'a' && frase[i] <= 'z')) {
            count++;
        }
    }
    printf("saindo da funcao!\n");
    return count;
}
int main() {
    int n;
    char frase[51];
    int letras;
    printf("Quantas sentencas voce deseja contar as letras?:\n");
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        printf("Digite a %d sentenca:\n", i);
        scanf(" %50[^\n]", frase);
        getchar(); // consome o '\n' após ler a frase
        printf("Chamando a funcao!\n");
        letras = contarLetras(frase);
        printf("Voltou da funcao!\n");
        printf("A sentenca %s possui %d %s\n", frase, letras, (letras == 1) ? "letra" : "letras");
    }
    return 0;
}