#include <stdio.h>
int main(){
    int n=10, prod=1, soma=0;
    int v[10];
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        soma+=v[i];
        prod=prod*v[i];
    }
    printf("Somatório:%d\n",soma);
    printf("Produtório:%d",prod);
    return 0;
}