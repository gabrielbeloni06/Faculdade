#include <stdio.h>
int main(){
    int q[10], mais=0;
    float v[10], total = 0, parcial = 0;
    for(int i=0;i<10;i++){
        scanf("%d",&q[i]);
    }
    for(int i=0;i<10;i++){
        scanf("%f",&v[i]);
    }
    for(int i=0;i<10;i++){
        parcial = q[i] * v[i];
        printf("Qnt %d, valor %.2f, Total %.2f",q[i],v[i], parcial);
        total += parcial;
    }
    printf("Total: %.2f\n",total);
    printf("Comissão: %.2f",total * 0.5);
    for(int i=0;i<10;i++){
        if(q[i] > mais){
            mais = q[i];
        }
    }
    for(int i=0;i<10;i++){
        if(q[i] == mais){
            printf("Posição: %d Valor:%.2f",i,v[i]);
        }
    }

}