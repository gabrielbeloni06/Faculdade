#include <stdio.h>
int main(){
    int v[5];
    for(int i=0;i<5;i++){
        scanf("%d",&v[i]);
    }
    for(int i=5;i>0;i--){
        printf("%d ",v[i-1]);
    }
}





/*Forma mais simples*/
#include <stdio.h>
int main(){
    int v[5];
    for(int i=0;i<5;i++){
        scanf("%d",&v[i]);
    }
    for(int i=4;i>=0;i--){//Usa o i=4 pois os vetores começam do 0, nunca chega a 5
        printf("%d ",v[i]);
    }
}



//Os códigos acima não trocam os vetores de lugar, apenas invertem a ordem de impressão. Para trocar os vetores de lugar, é necessário criar um vetor auxiliar e fazer a troca. Veja o código abaixo:
// Código para inverter os valores de um vetor, trocando os valores de lugar.
#include <stdio.h>
int main(){
    int v[20],fim=19,copy;
    for(int i=0;i<20;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<20;i++){
        copy = v[i];
        v[i]=v[fim];
        v[fim]=copy;
        fim--;
    }
    for(int i=0;i<20;i++){
        printf("%d ",v[i]);
    }
}