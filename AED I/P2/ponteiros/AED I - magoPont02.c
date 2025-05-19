#include <stdio.h>
void MaiorMenor(int *menor, int *maior, int a, int b, int c){
    if(a>b && a>c){
        *maior = a;
    }else if(b>c){
        *maior = b;
    }else{
        *maior = c;
    }
    if(a<b && a<c){
        *menor = a;
    }else if(b<c){
        *menor = b;
    }else{
        *menor = c;
    }
}
int main(){
    int a,b,c,menor,maior;
    scanf("%d %d %d",&a,&b,&c);
    MaiorMenor(&menor,&maior,a,b,c);
    printf("Maior=%d",maior);
    printf("Menor=%d",menor);
    return 0;
}