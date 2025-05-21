/*Imprime a matriz transposta*/
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
    for(int j=0; j<m;j++){
        for(int i=0;i<n;i++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*Armazena e imprime a matriz transposta*/
#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int mat[n][m];
    int copia[m][n];
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &mat[i][j]);
            copia[j][i]=mat[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",copia[i][j]);
        }
        printf("\n");
    }
    return 0;
}