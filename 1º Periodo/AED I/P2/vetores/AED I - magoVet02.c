#include <stdio.h>
#include <math.h>
int main(){
    int n = 10;
    float med=0, v[10],dP,var=0;
    for(int i=0;i<n;i++){
        scanf("%f",&v[i]);
        med+=v[i];
    }
    med=med/n;
    for(int i=0;i<n;i++){
        var+=(v[i]-med) * (v[i]-med);
    }
    var = var/n;
    dP=sqrt(var);
    printf("Média:%.2f\n",med);
    printf("Desvio Padrão:%.2f",dP);
    return 0;
}