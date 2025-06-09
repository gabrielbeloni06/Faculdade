#include <stdio.h>
int main (){
    int n,i,total;
    printf("Digite um numero:\n");
    scanf("%d",&n);
    i=n;
    total = 1;
    if(n==0){
        printf("O fatorial de 0 = 1");
    }
    else{
        while(n>1){
            total = total * n;
            n--;
        }
        printf("O fatorial de %d = %d",i,total);
    }
    return 0;
}