#include <stdio.h>
int main (){
    float n,conta,i,media;
    while(n!=-1){
        printf("Digite um numero (-1 para terminar):\n");
        scanf("%f",&n);
        if(n!=-1){
            conta=conta+n;
            i++;
        }
    }
    media=conta/i;
    printf("A media dos numeros fornecidos = %0.2f",media);
    return 0;
}