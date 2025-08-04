#include <stdio.h>
int main(){
    int n=100,a=0,b=1;
    int v[100];
    v[0]=a;
    v[1]=b;
    for(int i = 2;i<n;i++){
        v[i]=v[i-1]+v[i-2];
    }
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    return 0;
}