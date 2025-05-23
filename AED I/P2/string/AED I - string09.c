/*Copiando uma string para outra*/
#include <stdio.h>
int main(){
    char str[100];
    char str2[100];
    int i=0;
    scanf("%s",str);
    while(str[i]!='\0'){
        str2[i]=str[i];
        i++;
    }
    str2[i]='\0';
    printf("%s",str2);
    return 0;
}