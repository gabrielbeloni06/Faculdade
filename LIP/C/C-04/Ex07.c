// Exercicio 7 - Gabriel Egídio Santos Beloni
#include <stdio.h>
void compararForca(int forca1, int forca2) {
    printf("Estou no procedimento!\n");
    if (forca1 > forca2) {
        printf("%d > %d\n", forca1, forca2);
    } else if (forca2 > forca1) {
        printf("%d > %d\n", forca2, forca1);
    } else {
        printf("%d igual a %d\n", forca1, forca2);
    }
    printf("saindo do procedimento!\n");
}
int main() {
    int qtd, f1, f2;
    printf("Quantos conjuntos voce deseja verificar?:\n");
    scanf("%d", &qtd);
    for (int i = 1; i <= qtd; i++) {
        printf("conjunto %d:\n", i);
        printf("Digite a forca do 1 gigante:\n");
        scanf("%d", &f1);
        printf("Digite a forca do 2 gigante:\n");
        scanf("%d", &f2);
        printf("Chamando o procedimento!\n");
        compararForca(f1, f2);
        printf("Voltou do procedimento!\n");
    }
    return 0;
}