#include <stdio.h>
int main(){
    int n=100,r,a1;
    scanf("%d %d",&a1,&r);
    int v[100];
    v[0]=a1;
    for(int i=1;i<n;i++){
        v[i]=v[i-1]*r;
    }
    for(int i=0;i<n;i++){
        printf("%d",v[i]);
    }
    return 0;
}