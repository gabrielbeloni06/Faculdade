#include <stdio.h>
int divisao(int x, int y, int *res){
    if(x<y){
        *res=x;
        return 0;
    }
    else{
        return 1 + divisao(x-y,y,res);
    }
}
int main(){
    int x,y,quociente,resto;
    scanf("%d %d", &x, &y);
    quociente = divisao(x,y,&resto);
    printf("Resto:%d\n",resto);
    printf("Quociente:%d",quociente);
    return 0;
}