#include <stdio.h>
int main(){
    int n,m,soma=0;
    scanf("%d %d", &n, &m);
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &mat[i][j]);
            soma += mat[i][j];
        }
    }
    printf("Soma: %d", soma);

    return 0;
}