/*Leitura de entrada AAAAA (COM TAMANHO EM N)*/
#include <stdio.h>
int main(){
    char str[100];
    int n;
    scanf("%d%*c",&n); /*Faz com que leia 5 letras, sem ele lê apenas 4 pois o enter da entrada fica na frente*/
    for(int i=0;i<n;i++){
        scanf("%c",&str[i]);
    }
    for(int i=0;i<n;i++){
        printf("%c",str[i]);
    }
    str[n] = '\0';

    return 0;
}