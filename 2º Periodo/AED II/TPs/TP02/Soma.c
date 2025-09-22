#include <stdio.h>
#include <stdio.h>
int somaDeDigitos(const char* s){
    if(*s=='\0') return 0;
    int num = *s-'0';
    return num + somaDeDigitos(s+1);
}
int main(){
    char tag[]="FIM";
    char str[1000];
    scanf("%s",str);
    while(strcmp(str, tag)!=0){
        int soma = somaDeDigitos(str);
        printf("%d\n",soma);
        scanf("%s",str);
    }
    return 0;
}