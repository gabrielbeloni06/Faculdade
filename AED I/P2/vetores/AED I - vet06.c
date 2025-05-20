#include <stdio.h>
int main(){
    int mes[12], maior=0, menor=100;
    for(int i=0;i<12;i++){
        scanf("%d",&mes[i]);
    }
    for(int i=0;i<12;i++){
        if(mes[i] > maior){
            maior = mes[i];
        }
        if(mes[i] < menor){
            menor = mes[i];
        }
    }
    printf("Maior: %d\n",maior);
    printf("Menor: %d\n",menor);
}