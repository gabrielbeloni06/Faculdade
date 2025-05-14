#include <stdio.h>
int main (){
    int n,soma,v;
    soma=0;
    printf("Digite um numero:\n");
    scanf("%d",&n);
    v=n;
    while(n>0){
        soma = soma + n;
        n--;
    }
    printf("A soma de todos os numeros de 1 ate %d = %d",v,soma);
    return 0;
}