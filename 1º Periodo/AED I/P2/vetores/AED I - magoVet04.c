#include <stdio.h>
int main(){
    int n=10,soma=0;
    int v[10];
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        if(i%2==0){
            soma+=v[i];
        }
    }
    printf("A soma dos números de índice par é %d",soma);
    return 0;
}