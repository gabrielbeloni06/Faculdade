/*Função para rotacionar um vetor r vezes a direita*/
int *rotacionar(int *v,int n,int r){
    int *result=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        result[(i+r)%n]=v[i];
    }
    return result;
}