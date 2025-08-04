#include <stdio.h>
int main(){
    int a1,r,n=100;
    scanf("%d %d",&a1,&r);
    int v[100];
    v[0]=a1;
    for(int i=1;i<n;i++){
        v[i]=a1 + (r * i);
    }
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    return 0;
}