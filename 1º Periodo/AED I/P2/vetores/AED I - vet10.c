#include <stdio.h>
int main(){
    int n = 0;
    int v[6];
    for(int i=0;i<6;i++){
        scanf("%d",&v[i]);
        n+=v[i];
    }
    n = n/6;
    for(int i=0;i<6;i++){
        if(v[i]>n){
            printf("%d ",v[i]);
        }
    }
}


/*Usar if para verificar alguma situação, como v[i]>n*/