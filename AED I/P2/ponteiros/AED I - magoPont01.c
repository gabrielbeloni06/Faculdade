#include <stdio.h>
void Dobro(int *x){
    *x = (*x) * 2;
}
int main(){
    int num;
    scanf("%d", &num);
    printf("Antes: %d\n", num);
    Dobro(&num);
    printf("Depois: %d\n", num);
    return 0;
}