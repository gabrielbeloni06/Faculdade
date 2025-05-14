#include <stdio.h>
int main (){
    int n,soma,i;
    i=0;
    while (i<5){
        printf("Digite um numero:\n");
        scanf("%d",&n);
        soma = n * 3;
        printf("O tripo de %d = %d\n",n, soma);
        i++;
    }
    return 0;
}