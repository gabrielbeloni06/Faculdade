#include <stdio.h>
int pG(int a1,int r, int n){
    if(n==1){
        return a1;
    }
    return r*pG(a1,r,n-1);
}
int main(){
    int a1,r,n;
    scanf("%d %d %d",&a1,&r,&n);
    int resultado = pG(a1,r,n);
    printf("%d",resultado);
    return 0;
}