#include <stdio.h>
int main(){
    int v[100], copia, troca;
    for(int i = 0; i < 100; i++){
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    do{
        troca = 0;
        for(int i=0;i<99;i++){
            if(v[i]>v[i+1]){
                copia = v[i];
                v[i] = v[i+1];
                v[i+1] = copia;
                troca = 1;
            }
        }
    }while(troca);
    
    for(int i = 0; i < 100; i++){
        printf("%d ", v[i]);
    }
    return 0;
}