//Exercicio 8 - Gabriel Egídio Santos Beloni
#include <stdio.h>


int calcularPotencia(int base, int expoente) {
    printf("Estou na funcao!\n");
    int res = 1;
    for (int i = 0; i < expoente; i++) {
        res *= base;
    }
    printf("saindo da funcao!\n");
    return res;
}

int main() {
    int n, base, expo, resultado;


    printf("Quantas formulas deseja calcular?:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        printf("conjunto %d:\n", i);

        printf("Digite a base:\n");
        scanf("%d", &base);

        printf("Digite o expoente:\n");
        scanf("%d", &expo);
   
        printf("Chamando a funcao!\n");
        resultado = calcularPotencia(base, expo);
   
        printf("Voltou da funcao\n");
    
        printf("%d elevado a %d = %d\n", base, expo, resultado);
    }

    return 0;
}