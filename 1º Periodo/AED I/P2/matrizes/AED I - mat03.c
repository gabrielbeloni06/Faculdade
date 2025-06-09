/*Soma de matrizes*/
#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int A[n][m],B[n][m],C[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Matriz A[%d][%d]",i,j);
            scanf("%d", &A[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Matriz B[%d][%d]",i,j);
            scanf("%d", &B[i][j]);
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    printf("Soma das matrizes\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}