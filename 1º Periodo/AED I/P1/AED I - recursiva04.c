#include <stdio.h>
int PA(int num,int r,int termoInicial){
    if (num==1){
        return termoInicial;
    }
    return r+PA(termoInicial,r,num-1);
}
int main(){
    int num,r,termoInicial;
    scanf("%d %d %d",&num,&r,&termoInicial);
    int resultado = termoPA(termoInicial,r,num)
}