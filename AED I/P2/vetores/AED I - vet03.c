#include <stdio.h>
int main(){
    int v[10];
    int v2[10];
    for(int i=0;i<10;i++){
        scanf("%d",&v[i]);
        v2[i]=v[i]*v[i];
    }
    printf("Vetor 1: ");
    for(int i=0;i<10;i++){
        printf("%d ",v[i]);
    }
    printf("\nVetor 2: ");
    for(int i=0;i<10;i++){
        printf("%d ",v2[i]);
    }
}
