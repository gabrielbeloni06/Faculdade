/*Imprimir o valor ascii*/
#include <stdio.h>
int main(){
    char str[100];
    scanf("%s",str);
    for(int i=0;i<100;i++){
        printf("%c=%d\n",str[i],str[i]);
    }
}