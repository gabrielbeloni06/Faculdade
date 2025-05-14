#include <stdio.h>
int main(){
    int num1,num2,n,soma;
    num1 = 1;
    num2 = 1;
    do
    {
        printf("Digite um numero maior que 2:\n");
        scanf("%d",&n);
            if(n<3){printf("Numero invalido! Deve ser maior que 2.\n");
            }
    } while (n<3);
    printf("A sequencia de Fibonacci ate o %d termo: %d,%d",n, num1, num2);
    for(int i=2; i<n; i++){
        soma = num1+num2;
        num1 = num2;
        num2 = soma;
        printf(",%d",soma);
    }
    return 0;
}