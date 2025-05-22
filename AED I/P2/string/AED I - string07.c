/*Junção de duas strings*/
#include <stdio.h>
int main(){
    char str[100];
    char str2[100];
    printf("Digite a primeira string:\n");
    scanf("%s",str);
    printf("Digite a segunda string:\n");
    scanf("%s",str2);
    int i=0;
    while(str[i] !='\0'){
        i++;
    }
    int j=0;
    while(str2[j] !='\0'){
        str[i]=str2[j];
        j++;
        i++;
    }
    str[i]='\0';
    printf("%s\n",str);
    return 0;
}