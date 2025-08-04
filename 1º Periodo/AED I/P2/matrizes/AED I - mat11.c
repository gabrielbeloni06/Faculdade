/*Quadrado Mágico*/
#include <stdio.h>
int main(){
    int n,m,soma,total,count=0;
    scanf("%d %d",&n,&m);
    int mat[n][m];
    soma=0;
    if(n!=m)count++;
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            soma+=mat[i][i];
        }
        total=soma;
        soma=0;
        for(int i=0;i<n;i++){
            soma+=mat[i][n-1-i];
        }
        if(soma!=total)count++;
        else{
            for(int i=0;i<n;i++){
                soma=0;
                for(int j=0;j<m;j++){
                    soma+=mat[i][j];
                }
                if(total!=soma)count++;
            }
        }
            for(int j=0;j<m;j++){
                soma=0;
                for(int i=0;i<n;i++){
                    soma+=mat[i][j];
                }
                if(total!=soma)count++;
            }
        if(count>0)printf("Não é um quadrado mágico");
        else printf("É um quadrado mágico");
    }
    return 0;
}