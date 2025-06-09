#include <stdio.h>
#include <string.h>
void verificarParidade(int numero, char resultado[]) {
    printf("Estou no procedimento!\n");
    if (numero % 2 == 0) {
        strcpy(resultado, "par");
    } else {
        strcpy(resultado, "impar");
    }
    printf("saindo do procedimento!\n");
}
int main() {
    int qtd, numero;
    char resultado[10];
    printf("Quantos numeros voce deseja verificar?:\n");
    scanf("%d", &qtd);
    for (int i = 1; i <= qtd; i++) {
        printf("Digite um valor:\n");
        scanf("%d", &numero);
        printf("Chamando o procedimento!\n");
        verificarParidade(numero, resultado);
        printf("Voltou do procedimento!\n");
        printf("O numero %d : %s\n", numero, resultado);
    }
    return 0;
}