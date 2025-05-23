/*Achar uma substring dentro de uma string*/
#include <stdio.h>
int main(){
    char str[100];
    char achar[100];
    int i=0,pos=-1;
    printf("Insira a string\n");
    scanf("%s",str);
    printf("Insira o termo que deseja procurar\n");
    scanf("%s",achar);
    while(str[i]!='\0'){
        int j=0;
        while(achar[j]!='\0' && str[i+j]==achar[j]){
            j++;
        }
        if(achar[j]=='\0'){
            pos=i;
            break;
        }
        i++;
    }
    if(pos > -1){
        printf("A substring foi encontrada na posição %d\n",pos);
    }else{
        printf("Não possui essa substring dentro da primeira string\n");
    }
    return 0;
}