#include <stdio.h>
int main(){
    int v[25];
    int v2[25];
    int somav[25];
    for(int i=0;i<25;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<25;i++){
        scanf("%d",&v2[i]);
    }
    for(int i=0;i<25;i++){
        somav[i]=v[i]+v2[i];
        printf("%d ",somav[i]);
    }
}