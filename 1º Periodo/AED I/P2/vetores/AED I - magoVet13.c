#include <stdio.h>
int main(){
    int n=1000;
    int v[1000];
    int c[1000]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
        if(v[i]>=0 && v[i]<n){
            c[v[i]]++;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d: ",i);
        for(int j=0;j<c[i];j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}