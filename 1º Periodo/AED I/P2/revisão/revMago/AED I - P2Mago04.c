/*Recriar a 01 sem criar uma nova matriz*/
void rotacionar(int **mat,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int copy=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=copy;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            int copy=mat[i][j];
            mat[i][j]=mat[i][n-1-j];
            mat[i][n-1-j]=copy;
        }
    }
}