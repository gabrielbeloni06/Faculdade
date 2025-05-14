#include <stdio.h>
int main (){
    int n,t,total;
    t=0;
    while(n!=-1){
        printf("Digite um numero (-1) para ternimar:\n");
        scanf("%d",&n);
        if (n!=-1){
            t=t+n;
        }
    }
    printf("A soma dos numeros fornecidos = %d",t);
    return 0;
}