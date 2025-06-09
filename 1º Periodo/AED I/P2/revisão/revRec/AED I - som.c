#include <stdio.h>
int som(int n){
    if(n==0) return 0;
        return n + som(n - 1);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",som(n));
    return 0;    
}