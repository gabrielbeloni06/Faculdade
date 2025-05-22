/*Descobrir tamanho de string*/
#include <stdio.h>
int main(){
    char str[100];
    int i=0,tam=0;
    scanf("%s",str);
    while(str[i] !='\0'){
        tam++;
        i++;
    }
    printf("%s tem tamanho: %d",str,tam);
    return 0;
}