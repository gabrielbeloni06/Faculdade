#include <stdio.h>
float calcularMedia() {
    float valor, soma = 0;
    int contador = 0;
    printf("Estou no procedimento!\n");
    while (1) {
        printf("Digite um valor (FLAG valor negativo)\n");
        scanf("%f", &valor);
        if (valor < 0) {
            break;
        }
        soma += valor;
        contador++;
    }
    printf("saindo do procedimento!\n");
    if (contador == 0) {
        return 0.0;
    }
    return soma / contador;
}
int main() {
    int conjuntos;
    float media;
    printf("Quantos conjuntos voce deseja?:\n");
    scanf("%d", &conjuntos);
    for (int i = 1; i <= conjuntos; i++) {
        printf("Chamando o procedimento!\n");
        media = calcularMedia();
        printf("Voltou do procedimento!\n");
        printf("A media do %d conjunto foi:%.3f\n", i, media);
    }
    return 0;
}