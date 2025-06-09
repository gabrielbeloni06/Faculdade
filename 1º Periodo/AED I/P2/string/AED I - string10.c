/*Achar caractere dentro de uma string*/
#include <stdio.h>
int main(){
    char l;
    char str[100];
    int count=0;
    printf("Insira a frase\n");
    scanf("%s",str);
    printf("Insira uma letra para encontrar na string\n");
    scanf("%*c%c",&l);
    int i=0;
    while(str[i]!='\0'){
        if(l==str[i]){
            printf("%c aparece pela primeira vez no caractere %d",l,(i+1));
            count++;
            break;
        }
        i++;
    }
    if(count==0){
        printf("A letra %c não aparece na string",l);
    }
    return 0;
}