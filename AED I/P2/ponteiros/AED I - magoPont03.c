/*Método Usando Array*/
#include <stdio.h>
void calculo(int n, int *valores, int *min, int *max, float *med){
    *min=valores[0];
    *max=valores[0];
    *med=0;
    for(int i=0;i<n;i++){
        *med+=valores[i];
        if(valores[i]<*min){
            *min=valores[i];
        }else if(valores[i]>*max){
            *max=valores[i];
        }
    }
    *med=*med/(float)n;
}
int main(){
    int n,min=0,max=0;
    float med;
    scanf("%d",&n);
    int valores[n];
    for(int i=0;i<n;i++){
        scanf("%d",&valores[i]);
    }
    calculo(n,valores,&min,&max,&med);
    printf("Máximo:%d\n",max);
    printf("Mínimo:%d\n",min);
    printf("Média:%.2f\n",med);
    return 0;
}

/*Aritmética de ponteiros*/
#include <stdio.h>
void aritmetica(int n, int *valores, int *min, int *max, float *med){
    *min=*(valores);
    *max=*(valores);
    *med=0;
    for(int i=0;i<n;i++){
        *med+=*(valores+i);
        if(*(valores+i)<*min){
            *min=*(valores+i);
        }else if(*max<*(valores+i)){
            *max=*(valores+i);
        }
    }
    *med=*med/(float)n;
}
int main(){
    int n,min=0,max=0;
    float med;
    scanf("%d",&n);
    int valores[n];
    for(int i=0;i<n;i++){
        scanf("%d",&valores[i]);
    }
    aritmetica(n,valores,&min,&max,&med);
    printf("Máximo:%d\n",max);
    printf("Mínimo:%d\n",min);
    printf("Média:%.2f\n",med);
    return 0;
}