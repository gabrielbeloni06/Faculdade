#include <stdio.h>
int main(){ 
    int num,x1,x2;
    x1 = 1;
    printf("Digite um numero para ver sua tabuada:\n");
    scanf("%d",&num);
    for(int i=0;i<10;i++){
        x2 = num * x1;
        printf(" %d x  %d =  %d\n", num, x1, x2);
        x1++;
    }
    return 0;
}