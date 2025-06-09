#include <stdio.h>
void fatorial (int n){
    if(n<=0){
        return 1;
    }else{
        return (n * fatorial(n-1));
    }
}
int main(){
    int n;
    printf("Insira um valor");
    scanf("%d",&n);
    printf("%d",fatorial(n));
    return 0;
}