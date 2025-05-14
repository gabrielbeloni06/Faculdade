#include <stdio.h>
int main(){
    int a, *b, **c, ***d;
    scanf("%d",&a);
    b = &a;
    c = &b;
    d = &c;
    printf("Valor:%d Dobro:%d Triplo:%d Quadruplo:%d", a,2* *b,3* **c,4* ***d);
    return 0;
}