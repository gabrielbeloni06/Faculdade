/*Matriz preenchida por usuário*/
#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int mat[n][m];
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}