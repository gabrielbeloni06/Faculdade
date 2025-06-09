#include <stdio.h>
int main(){
    int num;
    char car;
    printf("Digite o tamanho do lado do quadrado:\n");
    scanf("%d",&num);
    printf("Digite um caractere para formar o quadrado:\n");
    scanf(" %c",&car);
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            printf("%c ",car);
        }
        printf("\n");
    }
    return 0;
}