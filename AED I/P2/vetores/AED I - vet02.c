#include <stdio.h>
int main(){
    int n;
    int v[10];
    for(int i=0;i<10;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<10;i++){
        v[i] = v[i] * 3;
    }
    for(int i=0;i<10;i++){
        printf("%d ",v[i]);
    }
    return 0;
}