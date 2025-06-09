/*Diagonal Secundária*/
#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int mat[n][m];
    if(m!=n){
        printf("Não é possível imprimir a diagonal\n");
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
        printf("%d ",mat[i][m-1-i]);
        }
    }
    return 0;
}
