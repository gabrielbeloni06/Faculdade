//Exercicio 4 - Gabriel Egídio Santos Beloni
#include <stdio.h>
float calcularMedia(float nota1, float nota2) {
    printf("Estou na funcao!\n");
    float media = (nota1 + nota2) / 2;
    printf("saindo da funcao!\n");
    return media;
}
int main() {
    int n;
    float nota1, nota2, media;
    printf("Quantos apresentacoes foram realizadas?:\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Digite as notas da %d apresentacao:\n", i);
        scanf("%f %f", &nota1, &nota2);
        printf("Chamando a funcao!\n");
        media = calcularMedia(nota1, nota2);
        printf("Voltou da funcao!\n");
        printf("Media final:%.2f\n", media);
    }
    return 0;
}