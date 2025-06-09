/*Função para rotacionar uma matriz em 90 graus*/
int **rotacionar(int **A,int n){
    int **B=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        B[i]=malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            B[j][n-1-i]=A[i][j];
        }
    }
    return B;
}