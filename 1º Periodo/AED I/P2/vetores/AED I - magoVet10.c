#include <stdio.h>
int main(){
    int n=1000;
    int v[1000];
    int c[1000]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<n;i++){
        if(v[i]>=0 && v[i]<n){
            c[v[i]]++;
        }
    }
    for(int i=0;i<n;i++){
        printf("O número %d, apareceu %d vezes\n",i,c[i]);
    }
    return 0;
}
