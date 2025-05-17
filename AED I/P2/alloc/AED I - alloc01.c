#include <stdio.h>
int main (){
    int *x;
    malloc(x*sizeof(int));
    if(x){
        printf("Alocação bem sucedida\n");
        printf("Valor de x antes: %d\n",*x);
        *x=50;
        printf("Valor de x depois: %d\n",*x);
    }else{
        printf("Falha na alocação\n");
    }
}