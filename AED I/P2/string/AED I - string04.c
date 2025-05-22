/*Impressão de cada termo separadamente*/
#include <stdio.h>
int main(){
    char str[100];
    int i=0;
    scanf("%s",str);/*Para de ler no primeiro espaço*/
    while(str[i]!='\0'){/*Quando chegar no final da string para*/
        printf("%c ",str[i]);
        i++;
    }
    return 0;
}