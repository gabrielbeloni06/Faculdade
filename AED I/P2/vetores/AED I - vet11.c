#include <stdio.h>
int main(){
    int v[10];
    int soma = 0;
    for(int i=0;i<10;i++){
        scanf("%d",&v[i]);
        soma+=v[i];
    }
    printf("%d\n",soma);
}