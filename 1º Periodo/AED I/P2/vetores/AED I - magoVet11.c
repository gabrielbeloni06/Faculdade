#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int v[4]={-1,-1,-1,-1};
    for(int i=3;i>=0;i--){
        if(n>0){
            v[i]=n%10;
            n=n/10;
        }
    }
    for(int i=0;i<4;i++)
        if(v[i]>=0){
            printf("%d ",v[i]);
        }
    return 0;
}