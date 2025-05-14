#include <stdio.h>
void maiorMenor(int *v, int tam, int *maior, int *menor){
    *menor=0;
    *maior=0;
  for(int i=0;i<tam;i++){
    if(*menor>*(v+i)){
        *menor=*(v+i);
    }
    if(*maior<*(v+i)){
        *menor=*(v+i);
    }
  }
}
int main(){
    int menor, maior, v[10];
    maiorMenor(v,10,&maior,&menor);
    printf("Maior: %d\n",maior);
    printf("Menor: %d\n",menor);
    return 0;
}   