#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int somaColunas[m], mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int j=0;j<m;j++){    
    somaColunas[j]=0;
        for(int i=0;i<n;i++){
            somaColunas[j] += mat[i][j];
        }
    }
    for(int j=0;j<m;j++){
        printf("Soma Coluna %d: %d \n", (j+1), somaColunas[j]);  
    }
    return 0;
}