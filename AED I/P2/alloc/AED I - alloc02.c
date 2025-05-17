#include <stdio.h>
int main(){
    int tam, *vet;
    scanf("%d", &tam);
    vet = malloc (tam * sizeof(int));
    if(vet){
        for(int i=0;i<tam;i++){
            scanf("%d", &vet+i);
            printf("Valor de vet = %d", *(vet +i));
        }
    }else{
        printf("Falha na alocação\n");
    }
    free(vet);

    return 0;
}