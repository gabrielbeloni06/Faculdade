/*Verificar se as strings são iguais*/
#include <stdio.h>
int main(){
    char str[100];
    char str2[100];
    int count=0;
    printf("Digite a primeira string:");
    scanf("%s",str);
    printf("Digite a segunda string:");
    scanf("%s",str2);
    int i=0;
    while(str[i]!='\0' || str2[i]!='\0'){
        if(str[i]!=str2[i]){
            count++;
        }
        i++;
    }
    if(count>0){
        printf("Não são iguais");
    }
    else{
        printf("São iguais.");
    }
    return 0;
}