#include <stdio.h>
int main (){
    int n;
    printf("Digite o valor inicial:\n");
    scanf("%d",&n);
    if(n%2==0){
        n++;
    }
    int i;
    i=0;
    while(i<10){
        printf("%d,",n);
        i++;
        n=n+2;
    }
    return 0;
}