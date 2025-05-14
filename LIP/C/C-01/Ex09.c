#include <stdio.h>
int main(){
    int num;
    printf("Digite a altura do triangulo de estrelas:\n");
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        for(int j = 0; j<i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}