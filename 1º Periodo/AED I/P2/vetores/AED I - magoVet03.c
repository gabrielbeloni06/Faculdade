#include <stdio.h>
int main(){
    int n=10, x, cont=0;
    int v[10];
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        if(x==v[i]){
            cont++;
        }
    }
    if(cont>0){
        printf("O número %d existe na sequência.",x);
    }else{
        printf("Não existe na sequência.");
    }

    return 0;
}