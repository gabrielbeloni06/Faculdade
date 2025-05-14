#include <stdio.h>
int main (){
    int numA,numB,numMaior;
    do
    {
        printf("Digite o primeiro numero competidor:\n");
        scanf("%d",&numA);
        printf("Digite o segundo numero competidor:\n");
        scanf("%d",&numB);
        if((numA>=0||numB>=0))
        if(numA>numB){
            printf("O numero %d e o vencedor!\n",numA);
            if(numA>numMaior){
                numMaior=numA;
            }
        }else{
            printf("O numero %d e o vencedor!\n",numB);
            if(numB>numMaior){
                numMaior = numB;
            }
        }
    } while (!((numA < 0 && numA % 2 == 0) || (numB < 0 && numB % 2 == 0)));
    printf("Numero maior de todos:%d\n",numMaior);
    return 0;
}