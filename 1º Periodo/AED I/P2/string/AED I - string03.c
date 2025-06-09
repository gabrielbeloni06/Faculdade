/*Passar de Maiúsculo para Minúsculo e vice-versa*/
#include <stdio.h>
int main(){
    char str[100];
    scanf("%s",str);
    /*Maiúsculo para minúsculo*/
    for(int i=0;i<100;i++){
        printf("%c=%d\n",str[i]+32,str[i]);
    }
    /*Minúsculo para Maiúsculo*/
    for(int i=0;i<100;i++){
        printf("%c=%d\n",str[i]-32,str[i]);
    }
}
/*+32 A=a*/
/*-32 a=A*/