#include <stdio.h>
int main(){
    int n=100, maior, menor;
    int v[100];
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    maior=v[0],menor=v[0];
    for(int i=0;i<n;i++){
        if(v[i]>maior){
            maior=v[i];
        }
        if(v[i]<menor){
            menor=v[i];
        }
    }
    printf("Maior:%d\n",maior);
    printf("Menor:%d",menor);
    return 0;
}