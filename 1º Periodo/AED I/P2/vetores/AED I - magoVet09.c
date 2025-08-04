#include <stdio.h>
int main(){
    int n=1000;
    int v[1000];
    int c[1000]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        if(v[i]>=0 && v[i]<n){
            c[v[i]]=1;
        }
    }
    int marcador = 1;
    for(int i=0;i<n;i++){
        if(c[i]==0){
            printf("%d não aparece.",i);
            marcador=0;
        }
    }
    if(marcador==1){
        printf("Todos os números apareceram.");
    }
    return 0;
}